function u=pdecode_LLRs(initial_LLRs,myfrozenlookup)
% 
%    Usage :
%       pdecode_LLRs(initial_LLRs,myfrozenlookup)
%
% initial_LLRs    : The channel-independent, initial LLRs, which is
%                   sufficient for a SC decoder.
% 无需极端路径度量值，由于是SC，所以可以直接根据最左边的LLR的正负号直接硬裁决。

global PCparams;

if(nargin==1) % When no special frozen-bits supplied
    myfrozenlookup=PCparams.FZlookup;
end

N=PCparams.N;

% Initializing the likelihoods (i.e. the right end of the butterfly str)
PCparams.LLR = 0; %PCparams.BITS=-1;  LLR之所以是2*N-1位，是因为比如是4位的码，那么有1+2+4个LLR需要算。

PCparams.LLR(N:2*N-1) = initial_LLRs;  %其中N到2*N-1的LLR是最右边的LLR

d_hat = zeros(N,1);
% finalLRs = zeros(N,1); %DEBUG
for j=1:N
    
%         i = bitreversed(j-1,PCparams.n) +1 ; 
        i = PCparams.bitreversedindices(j) +1 ; % "+1" is to compensate matlab indexing (starting with 1 instead of 0)
        %这里的i是反序重排过的
        updateLLR(i);
%         finalLRs(i) = PCparams.LLR(1); %DEBUG
        
    if myfrozenlookup(i) == -1
        if PCparams.LLR(1) > 0  %PCparams.LLR(1) 就是根据最左边的LLR硬裁决
            d_hat(i) = 0;
        else
            d_hat(i) = 1;
        end
    else
        d_hat(i) = myfrozenlookup(i);
    end
    
        updateBITS(d_hat(i),i);    %硬裁决每一个位之后，把计算出的当前的结果从左向右更新，以便后面的uhat的进一步运算
end

u = d_hat ( myfrozenlookup == -1);

end