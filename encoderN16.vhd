LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;

ENTITY encoderN16 IS
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
	out16                               :   OUT    std_logic
	);
END encoderN16;

ARCHITECTURE rtl OF encoderN16 IS

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

BEGIN

  Logical_Operator_out1_out1 <= in1 XOR in2;

  Logical_Operator_out2_out1 <= in3 XOR in4;

  Logical_Operator_out3_out1 <= in5 XOR in6;

  Logical_Operator_out4_out1 <= in7 XOR in8;

  Logical_Operator_out5_out1 <= in9 XOR in10;

  Logical_Operator_out6_out1 <= in11 XOR in12;

  Logical_Operator_out7_out1 <= in13 XOR in14;

  Logical_Operator_out8_out1 <= in15 XOR in16;

  Logical_Operator_out9_out1 <= Logical_Operator_out1_out1 XOR Logical_Operator_out2_out1;

  Logical_Operator_out10_out1 <= in2 XOR in4;

  Logical_Operator_out11_out1 <= Logical_Operator_out3_out1 XOR Logical_Operator_out4_out1;

  Logical_Operator_out12_out1 <= in6 XOR in8;

  Logical_Operator_out13_out1 <= Logical_Operator_out5_out1 XOR Logical_Operator_out6_out1;

  Logical_Operator_out14_out1 <= in10 XOR in12;

  Logical_Operator_out15_out1 <= Logical_Operator_out7_out1 XOR Logical_Operator_out8_out1;

  Logical_Operator_out16_out1 <= in14 XOR in16;

  Logical_Operator_out17_out1 <= Logical_Operator_out9_out1 XOR Logical_Operator_out11_out1;

  Logical_Operator_out18_out1 <= Logical_Operator_out10_out1 XOR Logical_Operator_out12_out1;

  Logical_Operator_out19_out1 <= Logical_Operator_out2_out1 XOR Logical_Operator_out4_out1;

  Logical_Operator_out20_out1 <= in4 XOR in8;

  Logical_Operator_out21_out1 <= Logical_Operator_out13_out1 XOR Logical_Operator_out15_out1;

  Logical_Operator_out22_out1 <= Logical_Operator_out14_out1 XOR Logical_Operator_out16_out1;

  Logical_Operator_out23_out1 <= Logical_Operator_out6_out1 XOR Logical_Operator_out8_out1;

  Logical_Operator_out24_out1 <= in12 XOR in16;

  Logical_Operator_out25_out1 <= Logical_Operator_out17_out1 XOR Logical_Operator_out21_out1;

  Logical_Operator_out26_out1 <= Logical_Operator_out18_out1 XOR Logical_Operator_out22_out1;

  Logical_Operator_out27_out1 <= Logical_Operator_out19_out1 XOR Logical_Operator_out23_out1;

  Logical_Operator_out28_out1 <= Logical_Operator_out20_out1 XOR Logical_Operator_out24_out1;

  Logical_Operator_out29_out1 <= Logical_Operator_out11_out1 XOR Logical_Operator_out15_out1;

  Logical_Operator_out30_out1 <= Logical_Operator_out12_out1 XOR Logical_Operator_out16_out1;

  Logical_Operator_out31_out1 <= Logical_Operator_out4_out1 XOR Logical_Operator_out8_out1;

  Logical_Operator_out32_out1 <= in8 XOR in16;

  out1 <= Logical_Operator_out25_out1;

  out2 <= Logical_Operator_out26_out1;

  out3 <= Logical_Operator_out27_out1;

  out4 <= Logical_Operator_out28_out1;

  out5 <= Logical_Operator_out29_out1;

  out6 <= Logical_Operator_out30_out1;

  out7 <= Logical_Operator_out31_out1;

  out8 <= Logical_Operator_out32_out1;

  out9 <= Logical_Operator_out21_out1;

  out10 <= Logical_Operator_out22_out1;

  out11 <= Logical_Operator_out23_out1;

  out12 <= Logical_Operator_out24_out1;

  out13 <= Logical_Operator_out15_out1;

  out14 <= Logical_Operator_out16_out1;

  out15 <= Logical_Operator_out8_out1;

  out16 <= in16;

END rtl;
