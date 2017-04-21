LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;

ENTITY encoderN4 IS
PORT( 
	in1                               :   IN    std_logic;
	in2                               :   IN    std_logic;
	in3                               :   IN    std_logic;
	in4                               :   IN    std_logic;
	out1                               :   OUT    std_logic;
	out2                               :   OUT    std_logic;
	out3                               :   OUT    std_logic;
	out4                               :   OUT    std_logic
	);
END encoderN4;

ARCHITECTURE rtl OF encoderN4 IS

  SIGNAL Logical_Operator_out1_out1            : std_logic;
  SIGNAL Logical_Operator_out2_out1            : std_logic;
  SIGNAL Logical_Operator_out3_out1            : std_logic;
  SIGNAL Logical_Operator_out4_out1            : std_logic;

BEGIN

  Logical_Operator_out1_out1 <= in1 XOR in2;

  Logical_Operator_out2_out1 <= in3 XOR in4;

  Logical_Operator_out3_out1 <= Logical_Operator_out1_out1 XOR Logical_Operator_out2_out1;

  Logical_Operator_out4_out1 <= in2 XOR in4;

  out1 <= Logical_Operator_out3_out1;

  out2 <= Logical_Operator_out4_out1;

  out3 <= Logical_Operator_out2_out1;

  out4 <= in4;

END rtl
