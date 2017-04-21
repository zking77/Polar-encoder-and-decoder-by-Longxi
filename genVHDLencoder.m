function genVHDLencoder(N)
%GENVHDLENCODER 生成N位的Polar Codes的编码器;N是码长，2的n次方是N；
n = ceil(log2(N));
fileName = sprintf('encoderN%d',N);

fID = fopen(sprintf('encoderN%d.vhd',N),'w');
fprintf(fID,'LIBRARY IEEE;\n');
fprintf(fID,'USE IEEE.std_logic_1164.ALL;\n');
fprintf(fID,'USE IEEE.numeric_std.ALL;\n\n');

fprintf(fID,'ENTITY %s IS\n',fileName);
fprintf(fID,'PORT( \n');
for i=1:N
    fprintf(fID,'\tin%d                               :   IN    std_logic;\n',i);
end

for i=1:N-1
    fprintf(fID,'\tout%d                               :   OUT    std_logic;\n',i);
end
fprintf(fID,'\tout%d                               :   OUT    std_logic\n',N);
fprintf(fID,'\t);\nEND %s;\n\n',fileName);

fprintf(fID,'ARCHITECTURE rtl OF %s IS\n\n',fileName);
for i=1:N*0.5*n
    fprintf(fID,'  SIGNAL Logical_Operator_out%d_out1            : std_logic;\n',i);
end

fprintf(fID,'\nBEGIN\n');

status = cell(1,N);%存储从左到右N位，不断更新，以便进一步的异或运算
indexStatus = 1;
indexRound = 1;%一共有n轮
distance = 2^(indexRound);
indexXOR = 1;

for i=1:N
    status(i) = {sprintf('in%d',i)};
end

% while distance ~= N

for round = 1:n
    distance = 2^(round);
    subRound = N/distance;%subRound指的是N/2,N/4,N/8...，代表每个竖排的XOR的相同子结构数目；
    for i = 1:subRound
        for j = 1:2^(round-1)
            start = j+(i - 1)*distance;
            strLogical = sprintf('Logical_Operator_out%d_out1',indexXOR);
            fprintf(fID,'\n  %s <= %s XOR %s;\n',strLogical,strjoin(status(start)),strjoin(status(start + distance/2)));
            indexXOR=indexXOR+1;
            status(start) = cellstr(strLogical);
        end
    end
end
indexRound = indexRound + 1;%一共有n轮
distance = 2^(indexRound);
% end

for i=1:N
    str = strjoin(status(i));
    fprintf(fID,'\n  out%d <= %s;\n',i,str);
end

fprintf(fID,'\nEND rtl;\n');

end

