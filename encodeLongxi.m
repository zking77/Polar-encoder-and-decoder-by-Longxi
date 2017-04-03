function encodeLongxi(N,K,design_channelstring,design_channelstate,silentflag,frozenbits) %Optional: N0, designSNRdB and silentflag (last three arguments)
%输入global PCparams可以看全局参数
global PCparams;
n = ceil(log2(N)); 
N = 2^n;
PCparams = struct('N', N, ...
    'K', K, ...
    'n', n, ...
    'bitreversedindices',zeros(N,1),...
    'index_of_first0_from_MSB',zeros(N,1),...
    'index_of_first1_from_MSB',zeros(N,1));

for i=1:N
    PCparams.bitreversedindices(i) = bin2dec(wrev(dec2bin(i-1,PCparams.n)));
    
    %FINDING FIRST INDEX OF '1'
    i_bin = dec2bin(i-1,PCparams.n);
    for lastlevel = 1:PCparams.n
        if i_bin(lastlevel) == '1'
            break;
        end
    end
    PCparams.index_of_first1_from_MSB(i) = lastlevel;
    
    %FINDING FIRST INDEX OF '0'
    i_bin = dec2bin(i-1,PCparams.n);
    for lastlevel = 1:PCparams.n
        if i_bin(lastlevel) == '0'
            break;
        end
    end
    PCparams.index_of_first0_from_MSB(i) = lastlevel;
end
fprintf('\n All polar coding parameters & resources initialized. (in a structure - "PCparams") \n');
disp(PCparams);
end