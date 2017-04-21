function updateLLR(i)
% 
% USAGE: 
%       updateLLR(i)
% 
%   Computes the i-th LLR from the tree structure (heap-like-storage)
%   (Sequence of i values follow bit-reversal order of first N integers)
% 
%
% Non-Recursive(iteration ) implementation of the SCD update Likelihoods routine
%

global PCparams;

n = PCparams.n;

if i==1
    nextlevel=n;
else
    
%     %%%%%%TO IMPROVE LATER%%%%%%%%%
%       %FINDING FIRST INDEX OF '1'
%     i_bin = dec2bin(i-1,n);
%     for lastlevel = 1:n
%         if i_bin(lastlevel) == '1'
%             break;
%         end
%     end
    %%%%%%%% IMPROVED %%%%%%%%%%%
        lastlevel = PCparams.index_of_first1_from_MSB(i);
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%


    %%%%%% Initialize with lowerconv() %%%%%%
        st = 2^(lastlevel-1);
        ed = 2^(lastlevel) -1;
        for indx = st:ed
            PCparams.LLR(indx) = lowerconv(...
                           PCparams.BITS(1,indx), ...
                           PCparams.LLR(ed+2*(indx-st)+1), ...
                           PCparams.LLR(ed+2*(indx-st)+2) ...
                           );%lowerconv就是g函数
        end
        nextlevel = lastlevel-1;
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Proceed upwards the TREE, with upperconv() till ROOT node
for lev = nextlevel :-1: 1
    st = 2^(lev-1);
    ed = 2^lev - 1;
    for indx = st:ed
        PCparams.LLR(indx) = upperconv(PCparams.LLR(ed+2*(indx-st)+1), ...
                       PCparams.LLR(ed+2*(indx-st)+2));%upperconv就是f函数
    end
end
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
end