library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity NAND4_AmarnathPatelVHDL is
    Port ( A : in STD_LOGIC;
           B : in STD_LOGIC;
           C : in STD_LOGIC;
           D : in STD_LOGIC;
           Y : out STD_LOGIC);
end NAND4_AmarnathPatelVHDL;

architecture Behavioral of NAND4_AmarnathPatelVHDL is
    signal D1, D2 : STD_LOGIC;  -- Intermediate signals
begin
    -- First NAND gate (A NAND B)
    D1 <= not (A and B);
    
    -- Second NAND gate (C NAND D)
    D2 <= not (C and D);
    
    -- Third NAND gate (D1 NAND D2)
    Y <= not (D1 and D2);
end Behavioral;
