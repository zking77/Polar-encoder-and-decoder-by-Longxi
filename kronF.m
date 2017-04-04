function [ Fii ] = kronF( n )
%kronF 通过克罗内克积生成生成矩阵F
%   n为log2（N）
F1 = [1 0;1 1];
Fii= [1 0;1 1];
for ii=1:n-1
    Fii = kron(F1,Fii);
end
end

