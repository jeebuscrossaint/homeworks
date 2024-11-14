library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
entity Mux2to1_AmarnathPatelVHDL is
    Port(s : in STD_LOGIC;
         x : in STD_LOGIC;
         y : in STD_LOGIC;
         mux : out STD_LOGIC
         );
end Mux2to1_AmarnathPatelVHDL;
architecture abc of Mux2to1_AmarnathPatelVHDL is
    signal w1, w2, w3 : STD_LOGIC;
begin
    w1 <= (s nand s); -- not s
    w2 <= (w1 nand x);
    w3 <= (s nand y);  
    
    mux <= w2 nand w3;
end abc;