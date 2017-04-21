function genVHDLencoder(N)
%GENVHDLENCODER 生成N位的Polar Codes的编码器;N是码长，2的n次方是N；
n = ceil(log2(N));
fileName = sprintf('encoderN%d',N);

fID = fopen(sprintf('encoderN%d.vhd',N),'w');
fprintf(fID,'LIBRARY IEEE;\n');
fprintf(fID,'USE IEEE.std_logic_1164.ALL;\n');
fprintf(fID,'USE IEEE.numeric_std.ALL;\n\n');
参考曹博的TB
fprintf(fID,'\nEND rtl;\n');

end

