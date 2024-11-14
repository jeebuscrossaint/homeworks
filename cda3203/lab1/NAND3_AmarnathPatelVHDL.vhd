library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity NAND3_AmarnathPatelVHDL is 
    Port (a : in STD_LOGIC;
          b : in STD_LOGIC;    
          c : in STD_LOGIC;
          y : out STD_LOGIC
          );
end NAND3_AmarnathPatelVHDL;

architecture abc of NAND3_AmarnathPatelVHDL is
begin
    y <= ((a nand b) nand (a nand b)) nand c;
end abc;