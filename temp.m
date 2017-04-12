function [ x ] = temp(x)
n = 8;
N = 256;
bitreversedindices=zeros(N,1);

for i=1:N
    bitreversedindices(i) = bin2dec(wrev(dec2bin(i-1,n)));
    %bitreversedindices用来存储反序重排的顺序
end

tempX = zeros(N,1);%tempX用来暂时存储反序重排后的x
for i=1:N
    tempX(i) = x(bitreversedindices(i)+1);
end
x=tempX;%x作为最后输出
end