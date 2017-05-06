function genTB_VHDLencoder(N)
%GENVHDLENCODER 生成N位的Polar Codes的编码器;N是码长，2的n次方是N；
n = ceil(log2(N));
fileName = sprintf('tbInVivado_encoderN%d',N);

fID = fopen(sprintf('tbInVivado_encoderN%d.TXT',N),'w');
for i=1:N
    fprintf(fID,'add_force {/encoderN%d/in%d} -radix hex {0 0ns};\n',N,i);
end

end

