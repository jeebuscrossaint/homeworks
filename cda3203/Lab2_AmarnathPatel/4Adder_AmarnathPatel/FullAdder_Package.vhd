LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

PACKAGE FullAdder_Package IS

-- full adder
	COMPONENT FullAdder_AmarnathPatelVHDL IS
	
		PORT(A,B,CIN		:IN STD_LOGIC;
			Cout,Sum	:OUT STD_LOGIC);
			
		END COMPONENT FullAdder_AmarnathPatelVHDL;
		
END PACKAGE FullAdder_Package;