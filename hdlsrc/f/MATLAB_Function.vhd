-- -------------------------------------------------------------
-- 
-- File Name: hdlsrc\f\MATLAB_Function.vhd
-- Created: 2017-04-20 12:58:25
-- 
-- Generated by MATLAB 9.1 and HDL Coder 3.9
-- 
-- -------------------------------------------------------------


-- -------------------------------------------------------------
-- 
-- Module: MATLAB_Function
-- Source Path: f/HDL_DUT/f/MATLAB Function
-- Hierarchy Level: 2
-- 
-- -------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;

ENTITY MATLAB_Function IS
  PORT( s                                 :   IN    std_logic;
        L                                 :   IN    std_logic_vector(7 DOWNTO 0);  -- int8
        y                                 :   OUT   std_logic_vector(7 DOWNTO 0)  -- int8
        );
END MATLAB_Function;


ARCHITECTURE rtl OF MATLAB_Function IS

  -- Signals
  SIGNAL L_signed                         : signed(7 DOWNTO 0);  -- int8
  SIGNAL y_tmp                            : signed(7 DOWNTO 0);  -- int8

BEGIN
  L_signed <= signed(L);

  MATLAB_Function_1_output : PROCESS (s, L_signed)
    VARIABLE t_0 : signed(8 DOWNTO 0);
  BEGIN
    IF s = '1' THEN 
      y_tmp <= L_signed;
    ELSE 
      t_0 :=  - (resize(L_signed, 9));
      IF (t_0(8) = '0') AND (t_0(7) /= '0') THEN 
        y_tmp <= "01111111";
      ELSIF (t_0(8) = '1') AND (t_0(7) /= '1') THEN 
        y_tmp <= "10000000";
      ELSE 
        y_tmp <= t_0(7 DOWNTO 0);
      END IF;
    END IF;
  END PROCESS MATLAB_Function_1_output;


  y <= std_logic_vector(y_tmp);

END rtl;

