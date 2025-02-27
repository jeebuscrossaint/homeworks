Library IEEE;
USE ieee.std_Logic_1164.all;
USE work.AdderPackage.all;

ENTITY Adder16_AmarnathPatelVHDL IS
	PORT(A, B	:IN std_logic_vector (15 downto 0);
		 Cin    :IN std_logic;
		 S		:OUT std_logic_vector (15 downto 0);
		 Cout	:OUT std_logic);
END Adder16_AmarnathPatelVHDL;

Architecture Structure of Adder16_AmarnathPatelVHDL is
	signal W: std_Logic_vector (14 downto 0); -- we need 14 because the last wire usings cout and the first one uses cin
	
Begin
	-- 16 chaining
	F0: FullAdder_AmarnathPatelVHDL PORT MAP (A(0), B(0), Cin, W(0), S(0));
	F1: FullAdder_AmarnathPatelVHDL PORT MAP (A(1), B(1), W(0), W(1), S(1));
	F2: FullAdder_AmarnathPatelVHDL PORT MAP (A(2), B(2), W(1), W(2), S(2));
	F3: FullAdder_AmarnathPatelVHDL PORT MAP (A(3), B(3), W(2), W(3), S(3));
	F4: FullAdder_AmarnathPatelVHDL PORT MAP (A(4), B(4), W(3), W(4), S(4));
	F5: FullAdder_AmarnathPatelVHDL PORT MAP (A(5), B(5), W(4), W(5), S(5));
	F6: FullAdder_AmarnathPatelVHDL PORT MAP (A(6), B(6), W(5), W(6), S(6));
	F7: FullAdder_AmarnathPatelVHDL PORT MAP (A(7), B(7), W(6), W(7), S(7));
	F8: FullAdder_AmarnathPatelVHDL PORT MAP (A(8), B(8), W(7), W(8), S(8));
	F9: FullAdder_AmarnathPatelVHDL PORT MAP (A(9), B(9), W(8), W(9), S(9));
	F10: FullAdder_AmarnathPatelVHDL PORT MAP (A(10), B(10), W(9), W(10), S(10));
	F11: FullAdder_AmarnathPatelVHDL PORT MAP (A(11), B(11), W(10), W(11), S(11));
	F12: FullAdder_AmarnathPatelVHDL PORT MAP (A(12), B(12), W(11), W(12), S(12));
	F13: FullAdder_AmarnathPatelVHDL PORT MAP (A(13), B(13), W(12), W(13), S(13));
	F14: FullAdder_AmarnathPatelVHDL PORT MAP (A(14), B(14), W(13), W(14), S(14));
	F15: FullAdder_AmarnathPatelVHDL PORT MAP (A(15), B(15), W(14), Cout, S(15));
end Structure;
	