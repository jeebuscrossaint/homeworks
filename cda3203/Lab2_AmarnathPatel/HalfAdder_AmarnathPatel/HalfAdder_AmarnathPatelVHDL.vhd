library ieee;
use ieee.std_logic_1164.all;

entity HalfAdder_AmarnathPatelVHDL is
    Port ( A : in  STD_LOGIC;
           B : in  STD_LOGIC;
           Sum : out STD_LOGIC;
           Cout : out STD_LOGIC);
end entity HalfAdder_AmarnathPatelVHDL;

architecture Behavioral of HalfAdder_AmarnathPatelVHDL is
begin
    -- Implement Sum and Carry using only NAND gates
    Sum <= (A NAND (A NAND B)) NAND (B NAND (A NAND B));
    Cout <= ((A NAND B) NAND (A NAND B));
end Behavioral;