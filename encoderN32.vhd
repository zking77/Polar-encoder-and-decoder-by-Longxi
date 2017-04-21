LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;

ENTITY encoderN32 IS
PORT( 
	in1                               :   IN    std_logic;
	in2                               :   IN    std_logic;
	in3                               :   IN    std_logic;
	in4                               :   IN    std_logic;
	in5                               :   IN    std_logic;
	in6                               :   IN    std_logic;
	in7                               :   IN    std_logic;
	in8                               :   IN    std_logic;
	in9                               :   IN    std_logic;
	in10                               :   IN    std_logic;
	in11                               :   IN    std_logic;
	in12                               :   IN    std_logic;
	in13                               :   IN    std_logic;
	in14                               :   IN    std_logic;
	in15                               :   IN    std_logic;
	in16                               :   IN    std_logic;
	in17                               :   IN    std_logic;
	in18                               :   IN    std_logic;
	in19                               :   IN    std_logic;
	in20                               :   IN    std_logic;
	in21                               :   IN    std_logic;
	in22                               :   IN    std_logic;
	in23                               :   IN    std_logic;
	in24                               :   IN    std_logic;
	in25                               :   IN    std_logic;
	in26                               :   IN    std_logic;
	in27                               :   IN    std_logic;
	in28                               :   IN    std_logic;
	in29                               :   IN    std_logic;
	in30                               :   IN    std_logic;
	in31                               :   IN    std_logic;
	in32                               :   IN    std_logic;
	out1                               :   OUT    std_logic;
	out2                               :   OUT    std_logic;
	out3                               :   OUT    std_logic;
	out4                               :   OUT    std_logic;
	out5                               :   OUT    std_logic;
	out6                               :   OUT    std_logic;
	out7                               :   OUT    std_logic;
	out8                               :   OUT    std_logic;
	out9                               :   OUT    std_logic;
	out10                               :   OUT    std_logic;
	out11                               :   OUT    std_logic;
	out12                               :   OUT    std_logic;
	out13                               :   OUT    std_logic;
	out14                               :   OUT    std_logic;
	out15                               :   OUT    std_logic;
	out16                               :   OUT    std_logic;
	out17                               :   OUT    std_logic;
	out18                               :   OUT    std_logic;
	out19                               :   OUT    std_logic;
	out20                               :   OUT    std_logic;
	out21                               :   OUT    std_logic;
	out22                               :   OUT    std_logic;
	out23                               :   OUT    std_logic;
	out24                               :   OUT    std_logic;
	out25                               :   OUT    std_logic;
	out26                               :   OUT    std_logic;
	out27                               :   OUT    std_logic;
	out28                               :   OUT    std_logic;
	out29                               :   OUT    std_logic;
	out30                               :   OUT    std_logic;
	out31                               :   OUT    std_logic;
	out32                               :   OUT    std_logic
	);
END encoderN32;

ARCHITECTURE rtl OF encoderN32 IS

  SIGNAL Logical_Operator_out1_out1            : std_logic;
  SIGNAL Logical_Operator_out2_out1            : std_logic;
  SIGNAL Logical_Operator_out3_out1            : std_logic;
  SIGNAL Logical_Operator_out4_out1            : std_logic;
  SIGNAL Logical_Operator_out5_out1            : std_logic;
  SIGNAL Logical_Operator_out6_out1            : std_logic;
  SIGNAL Logical_Operator_out7_out1            : std_logic;
  SIGNAL Logical_Operator_out8_out1            : std_logic;
  SIGNAL Logical_Operator_out9_out1            : std_logic;
  SIGNAL Logical_Operator_out10_out1            : std_logic;
  SIGNAL Logical_Operator_out11_out1            : std_logic;
  SIGNAL Logical_Operator_out12_out1            : std_logic;
  SIGNAL Logical_Operator_out13_out1            : std_logic;
  SIGNAL Logical_Operator_out14_out1            : std_logic;
  SIGNAL Logical_Operator_out15_out1            : std_logic;
  SIGNAL Logical_Operator_out16_out1            : std_logic;
  SIGNAL Logical_Operator_out17_out1            : std_logic;
  SIGNAL Logical_Operator_out18_out1            : std_logic;
  SIGNAL Logical_Operator_out19_out1            : std_logic;
  SIGNAL Logical_Operator_out20_out1            : std_logic;
  SIGNAL Logical_Operator_out21_out1            : std_logic;
  SIGNAL Logical_Operator_out22_out1            : std_logic;
  SIGNAL Logical_Operator_out23_out1            : std_logic;
  SIGNAL Logical_Operator_out24_out1            : std_logic;
  SIGNAL Logical_Operator_out25_out1            : std_logic;
  SIGNAL Logical_Operator_out26_out1            : std_logic;
  SIGNAL Logical_Operator_out27_out1            : std_logic;
  SIGNAL Logical_Operator_out28_out1            : std_logic;
  SIGNAL Logical_Operator_out29_out1            : std_logic;
  SIGNAL Logical_Operator_out30_out1            : std_logic;
  SIGNAL Logical_Operator_out31_out1            : std_logic;
  SIGNAL Logical_Operator_out32_out1            : std_logic;
  SIGNAL Logical_Operator_out33_out1            : std_logic;
  SIGNAL Logical_Operator_out34_out1            : std_logic;
  SIGNAL Logical_Operator_out35_out1            : std_logic;
  SIGNAL Logical_Operator_out36_out1            : std_logic;
  SIGNAL Logical_Operator_out37_out1            : std_logic;
  SIGNAL Logical_Operator_out38_out1            : std_logic;
  SIGNAL Logical_Operator_out39_out1            : std_logic;
  SIGNAL Logical_Operator_out40_out1            : std_logic;
  SIGNAL Logical_Operator_out41_out1            : std_logic;
  SIGNAL Logical_Operator_out42_out1            : std_logic;
  SIGNAL Logical_Operator_out43_out1            : std_logic;
  SIGNAL Logical_Operator_out44_out1            : std_logic;
  SIGNAL Logical_Operator_out45_out1            : std_logic;
  SIGNAL Logical_Operator_out46_out1            : std_logic;
  SIGNAL Logical_Operator_out47_out1            : std_logic;
  SIGNAL Logical_Operator_out48_out1            : std_logic;
  SIGNAL Logical_Operator_out49_out1            : std_logic;
  SIGNAL Logical_Operator_out50_out1            : std_logic;
  SIGNAL Logical_Operator_out51_out1            : std_logic;
  SIGNAL Logical_Operator_out52_out1            : std_logic;
  SIGNAL Logical_Operator_out53_out1            : std_logic;
  SIGNAL Logical_Operator_out54_out1            : std_logic;
  SIGNAL Logical_Operator_out55_out1            : std_logic;
  SIGNAL Logical_Operator_out56_out1            : std_logic;
  SIGNAL Logical_Operator_out57_out1            : std_logic;
  SIGNAL Logical_Operator_out58_out1            : std_logic;
  SIGNAL Logical_Operator_out59_out1            : std_logic;
  SIGNAL Logical_Operator_out60_out1            : std_logic;
  SIGNAL Logical_Operator_out61_out1            : std_logic;
  SIGNAL Logical_Operator_out62_out1            : std_logic;
  SIGNAL Logical_Operator_out63_out1            : std_logic;
  SIGNAL Logical_Operator_out64_out1            : std_logic;
  SIGNAL Logical_Operator_out65_out1            : std_logic;
  SIGNAL Logical_Operator_out66_out1            : std_logic;
  SIGNAL Logical_Operator_out67_out1            : std_logic;
  SIGNAL Logical_Operator_out68_out1            : std_logic;
  SIGNAL Logical_Operator_out69_out1            : std_logic;
  SIGNAL Logical_Operator_out70_out1            : std_logic;
  SIGNAL Logical_Operator_out71_out1            : std_logic;
  SIGNAL Logical_Operator_out72_out1            : std_logic;
  SIGNAL Logical_Operator_out73_out1            : std_logic;
  SIGNAL Logical_Operator_out74_out1            : std_logic;
  SIGNAL Logical_Operator_out75_out1            : std_logic;
  SIGNAL Logical_Operator_out76_out1            : std_logic;
  SIGNAL Logical_Operator_out77_out1            : std_logic;
  SIGNAL Logical_Operator_out78_out1            : std_logic;
  SIGNAL Logical_Operator_out79_out1            : std_logic;
  SIGNAL Logical_Operator_out80_out1            : std_logic;

BEGIN

  Logical_Operator_out1_out1 <= in1 XOR in2;

  Logical_Operator_out2_out1 <= in3 XOR in4;

  Logical_Operator_out3_out1 <= in5 XOR in6;

  Logical_Operator_out4_out1 <= in7 XOR in8;

  Logical_Operator_out5_out1 <= in9 XOR in10;

  Logical_Operator_out6_out1 <= in11 XOR in12;

  Logical_Operator_out7_out1 <= in13 XOR in14;

  Logical_Operator_out8_out1 <= in15 XOR in16;

  Logical_Operator_out9_out1 <= in17 XOR in18;

  Logical_Operator_out10_out1 <= in19 XOR in20;

  Logical_Operator_out11_out1 <= in21 XOR in22;

  Logical_Operator_out12_out1 <= in23 XOR in24;

  Logical_Operator_out13_out1 <= in25 XOR in26;

  Logical_Operator_out14_out1 <= in27 XOR in28;

  Logical_Operator_out15_out1 <= in29 XOR in30;

  Logical_Operator_out16_out1 <= in31 XOR in32;

  Logical_Operator_out17_out1 <= Logical_Operator_out1_out1 XOR Logical_Operator_out2_out1;

  Logical_Operator_out18_out1 <= in2 XOR in4;

  Logical_Operator_out19_out1 <= Logical_Operator_out3_out1 XOR Logical_Operator_out4_out1;

  Logical_Operator_out20_out1 <= in6 XOR in8;

  Logical_Operator_out21_out1 <= Logical_Operator_out5_out1 XOR Logical_Operator_out6_out1;

  Logical_Operator_out22_out1 <= in10 XOR in12;

  Logical_Operator_out23_out1 <= Logical_Operator_out7_out1 XOR Logical_Operator_out8_out1;

  Logical_Operator_out24_out1 <= in14 XOR in16;

  Logical_Operator_out25_out1 <= Logical_Operator_out9_out1 XOR Logical_Operator_out10_out1;

  Logical_Operator_out26_out1 <= in18 XOR in20;

  Logical_Operator_out27_out1 <= Logical_Operator_out11_out1 XOR Logical_Operator_out12_out1;

  Logical_Operator_out28_out1 <= in22 XOR in24;

  Logical_Operator_out29_out1 <= Logical_Operator_out13_out1 XOR Logical_Operator_out14_out1;

  Logical_Operator_out30_out1 <= in26 XOR in28;

  Logical_Operator_out31_out1 <= Logical_Operator_out15_out1 XOR Logical_Operator_out16_out1;

  Logical_Operator_out32_out1 <= in30 XOR in32;

  Logical_Operator_out33_out1 <= Logical_Operator_out17_out1 XOR Logical_Operator_out19_out1;

  Logical_Operator_out34_out1 <= Logical_Operator_out18_out1 XOR Logical_Operator_out20_out1;

  Logical_Operator_out35_out1 <= Logical_Operator_out2_out1 XOR Logical_Operator_out4_out1;

  Logical_Operator_out36_out1 <= in4 XOR in8;

  Logical_Operator_out37_out1 <= Logical_Operator_out21_out1 XOR Logical_Operator_out23_out1;

  Logical_Operator_out38_out1 <= Logical_Operator_out22_out1 XOR Logical_Operator_out24_out1;

  Logical_Operator_out39_out1 <= Logical_Operator_out6_out1 XOR Logical_Operator_out8_out1;

  Logical_Operator_out40_out1 <= in12 XOR in16;

  Logical_Operator_out41_out1 <= Logical_Operator_out25_out1 XOR Logical_Operator_out27_out1;

  Logical_Operator_out42_out1 <= Logical_Operator_out26_out1 XOR Logical_Operator_out28_out1;

  Logical_Operator_out43_out1 <= Logical_Operator_out10_out1 XOR Logical_Operator_out12_out1;

  Logical_Operator_out44_out1 <= in20 XOR in24;

  Logical_Operator_out45_out1 <= Logical_Operator_out29_out1 XOR Logical_Operator_out31_out1;

  Logical_Operator_out46_out1 <= Logical_Operator_out30_out1 XOR Logical_Operator_out32_out1;

  Logical_Operator_out47_out1 <= Logical_Operator_out14_out1 XOR Logical_Operator_out16_out1;

  Logical_Operator_out48_out1 <= in28 XOR in32;

  Logical_Operator_out49_out1 <= Logical_Operator_out33_out1 XOR Logical_Operator_out37_out1;

  Logical_Operator_out50_out1 <= Logical_Operator_out34_out1 XOR Logical_Operator_out38_out1;

  Logical_Operator_out51_out1 <= Logical_Operator_out35_out1 XOR Logical_Operator_out39_out1;

  Logical_Operator_out52_out1 <= Logical_Operator_out36_out1 XOR Logical_Operator_out40_out1;

  Logical_Operator_out53_out1 <= Logical_Operator_out19_out1 XOR Logical_Operator_out23_out1;

  Logical_Operator_out54_out1 <= Logical_Operator_out20_out1 XOR Logical_Operator_out24_out1;

  Logical_Operator_out55_out1 <= Logical_Operator_out4_out1 XOR Logical_Operator_out8_out1;

  Logical_Operator_out56_out1 <= in8 XOR in16;

  Logical_Operator_out57_out1 <= Logical_Operator_out41_out1 XOR Logical_Operator_out45_out1;

  Logical_Operator_out58_out1 <= Logical_Operator_out42_out1 XOR Logical_Operator_out46_out1;

  Logical_Operator_out59_out1 <= Logical_Operator_out43_out1 XOR Logical_Operator_out47_out1;

  Logical_Operator_out60_out1 <= Logical_Operator_out44_out1 XOR Logical_Operator_out48_out1;

  Logical_Operator_out61_out1 <= Logical_Operator_out27_out1 XOR Logical_Operator_out31_out1;

  Logical_Operator_out62_out1 <= Logical_Operator_out28_out1 XOR Logical_Operator_out32_out1;

  Logical_Operator_out63_out1 <= Logical_Operator_out12_out1 XOR Logical_Operator_out16_out1;

  Logical_Operator_out64_out1 <= in24 XOR in32;

  Logical_Operator_out65_out1 <= Logical_Operator_out49_out1 XOR Logical_Operator_out57_out1;

  Logical_Operator_out66_out1 <= Logical_Operator_out50_out1 XOR Logical_Operator_out58_out1;

  Logical_Operator_out67_out1 <= Logical_Operator_out51_out1 XOR Logical_Operator_out59_out1;

  Logical_Operator_out68_out1 <= Logical_Operator_out52_out1 XOR Logical_Operator_out60_out1;

  Logical_Operator_out69_out1 <= Logical_Operator_out53_out1 XOR Logical_Operator_out61_out1;

  Logical_Operator_out70_out1 <= Logical_Operator_out54_out1 XOR Logical_Operator_out62_out1;

  Logical_Operator_out71_out1 <= Logical_Operator_out55_out1 XOR Logical_Operator_out63_out1;

  Logical_Operator_out72_out1 <= Logical_Operator_out56_out1 XOR Logical_Operator_out64_out1;

  Logical_Operator_out73_out1 <= Logical_Operator_out37_out1 XOR Logical_Operator_out45_out1;

  Logical_Operator_out74_out1 <= Logical_Operator_out38_out1 XOR Logical_Operator_out46_out1;

  Logical_Operator_out75_out1 <= Logical_Operator_out39_out1 XOR Logical_Operator_out47_out1;

  Logical_Operator_out76_out1 <= Logical_Operator_out40_out1 XOR Logical_Operator_out48_out1;

  Logical_Operator_out77_out1 <= Logical_Operator_out23_out1 XOR Logical_Operator_out31_out1;

  Logical_Operator_out78_out1 <= Logical_Operator_out24_out1 XOR Logical_Operator_out32_out1;

  Logical_Operator_out79_out1 <= Logical_Operator_out8_out1 XOR Logical_Operator_out16_out1;

  Logical_Operator_out80_out1 <= in16 XOR in32;

  out1 <= Logical_Operator_out65_out1;

  out2 <= Logical_Operator_out66_out1;

  out3 <= Logical_Operator_out67_out1;

  out4 <= Logical_Operator_out68_out1;

  out5 <= Logical_Operator_out69_out1;

  out6 <= Logical_Operator_out70_out1;

  out7 <= Logical_Operator_out71_out1;

  out8 <= Logical_Operator_out72_out1;

  out9 <= Logical_Operator_out73_out1;

  out10 <= Logical_Operator_out74_out1;

  out11 <= Logical_Operator_out75_out1;

  out12 <= Logical_Operator_out76_out1;

  out13 <= Logical_Operator_out77_out1;

  out14 <= Logical_Operator_out78_out1;

  out15 <= Logical_Operator_out79_out1;

  out16 <= Logical_Operator_out80_out1;

  out17 <= Logical_Operator_out57_out1;

  out18 <= Logical_Operator_out58_out1;

  out19 <= Logical_Operator_out59_out1;

  out20 <= Logical_Operator_out60_out1;

  out21 <= Logical_Operator_out61_out1;

  out22 <= Logical_Operator_out62_out1;

  out23 <= Logical_Operator_out63_out1;

  out24 <= Logical_Operator_out64_out1;

  out25 <= Logical_Operator_out45_out1;

  out26 <= Logical_Operator_out46_out1;

  out27 <= Logical_Operator_out47_out1;

  out28 <= Logical_Operator_out48_out1;

  out29 <= Logical_Operator_out31_out1;

  out30 <= Logical_Operator_out32_out1;

  out31 <= Logical_Operator_out16_out1;

  out32 <= in32;

END rtl;
