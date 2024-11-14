LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE WORK.FullAdder_Package.all;

ENTITY Adder4_AmarnathPatelVHDL IS
    PORT(
        A, B   : IN STD_LOGIC_VECTOR(3 downto 0);
        Cin    : IN STD_LOGIC;
        S      : OUT STD_LOGIC_VECTOR(3 downto 0);
        Cout   : OUT STD_LOGIC
    );
END Adder4_AmarnathPatelVHDL;

ARCHITECTURE Structure OF Adder4_AmarnathPatelVHDL IS
    SIGNAL W: STD_LOGIC_VECTOR(2 downto 0);
    
    COMPONENT FullAdder_AmarnathPatelVHDL IS
        PORT(
            A, B, CIN : IN STD_LOGIC;
            Cout, Sum : OUT STD_LOGIC
        );
    END COMPONENT FullAdder_AmarnathPatelVHDL;

BEGIN
    -- Instantiation of Full Adder components for each bit position
    F0 : FullAdder_AmarnathPatelVHDL PORT MAP (A(0), B(0), Cin, W(0), S(0));
    F1 : FullAdder_AmarnathPatelVHDL PORT MAP (A(1), B(1), W(0), W(1), S(1));
    F2 : FullAdder_AmarnathPatelVHDL PORT MAP (A(2), B(2), W(1), W(2), S(2));
    F3 : FullAdder_AmarnathPatelVHDL PORT MAP (A(3), B(3), W(2), Cout, S(3));

END Structure;
