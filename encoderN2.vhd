LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;

ENTITY encoderN2 IS
PORT( 
	in1                               :   IN    std_logic;
	in2                               :   IN    std_logic;
	out1                               :   OUT    std_logic;
	out2                               :   OUT    std_logic
	);
END encoderN2;

ARCHITECTURE rtl OF encoderN2 IS

  SIGNAL Logical_Operator_out1_out1            : std_logic;

BEGIN

  Logical_Operator_out1_out1 <= in1 XOR in2;

  out1 <= Logical_Operator_out1_out1;

  out2 <= in2;

END rtl;
