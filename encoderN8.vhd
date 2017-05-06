LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;

ENTITY encoderN8 IS
PORT( 
	in1                               :   IN    std_logic;
	in2                               :   IN    std_logic;
	in3                               :   IN    std_logic;
	in4                               :   IN    std_logic;
	in5                               :   IN    std_logic;
	in6                               :   IN    std_logic;
	in7                               :   IN    std_logic;
	in8                               :   IN    std_logic;
	out1                               :   OUT    std_logic;
	out2                               :   OUT    std_logic;
	out3                               :   OUT    std_logic;
	out4                               :   OUT    std_logic;
	out5                               :   OUT    std_logic;
	out6                               :   OUT    std_logic;
	out7                               :   OUT    std_logic;
	out8                               :   OUT    std_logic
	);
END encoderN8;

ARCHITECTURE rtl OF encoderN8 IS

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

BEGIN

  Logical_Operator_out1_out1 <= in1 XOR in2;

  Logical_Operator_out2_out1 <= in3 XOR in4;

  Logical_Operator_out3_out1 <= in5 XOR in6;

  Logical_Operator_out4_out1 <= in7 XOR in8;

  Logical_Operator_out5_out1 <= Logical_Operator_out1_out1 XOR Logical_Operator_out2_out1;

  Logical_Operator_out6_out1 <= in2 XOR in4;

  Logical_Operator_out7_out1 <= Logical_Operator_out3_out1 XOR Logical_Operator_out4_out1;

  Logical_Operator_out8_out1 <= in6 XOR in8;

  Logical_Operator_out9_out1 <= Logical_Operator_out5_out1 XOR Logical_Operator_out7_out1;

  Logical_Operator_out10_out1 <= Logical_Operator_out6_out1 XOR Logical_Operator_out8_out1;

  Logical_Operator_out11_out1 <= Logical_Operator_out2_out1 XOR Logical_Operator_out4_out1;

  Logical_Operator_out12_out1 <= in4 XOR in8;

  out1 <= Logical_Operator_out9_out1;

  out2 <= Logical_Operator_out10_out1;

  out3 <= Logical_Operator_out11_out1;

  out4 <= Logical_Operator_out12_out1;

  out5 <= Logical_Operator_out7_out1;

  out6 <= Logical_Operator_out8_out1;

  out7 <= Logical_Operator_out4_out1;

  out8 <= in8;

END rtl;
