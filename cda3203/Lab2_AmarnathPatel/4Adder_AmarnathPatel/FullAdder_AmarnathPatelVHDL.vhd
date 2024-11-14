library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity FullAdder_AmarnathPatelVHDL is
    port (
        A, B, CIN : in STD_LOGIC;
        SUM, COUT : out STD_LOGIC
    );
end FullAdder_AmarnathPatelVHDL;

architecture nand_only of FullAdder_AmarnathPatelVHDL is
    signal nand_out : STD_LOGIC_VECTOR(0 to 10) := (others => '0'); -- Vector to hold NAND outputs
begin
    -- Intermediate NAND calculations for A XOR B
    nand_out(0) <= A NAND B;                     -- NAND of A and B
    nand_out(1) <= A NAND nand_out(0);           -- NAND of A and NAND_AB
    nand_out(2) <= B NAND nand_out(0);           -- NAND of B and NAND_AB
    nand_out(3) <= nand_out(1) NAND nand_out(2); -- A XOR B result

    -- SUM calculation (A XOR B) XOR CIN
    nand_out(4) <= nand_out(3) NAND CIN;         -- NAND of (A XOR B) and CIN
    nand_out(5) <= nand_out(3) NAND nand_out(4); -- Part of SUM logic
    nand_out(6) <= CIN NAND nand_out(4);         -- Part of SUM logic
    SUM <= nand_out(5) NAND nand_out(6);         -- Final SUM output

    -- COUT calculation (A AND B) OR (CIN AND (A XOR B))
    nand_out(7) <= A NAND nand_out(1);           -- Part of A AND B
    nand_out(8) <= B NAND nand_out(2);           -- Part of A AND B
    nand_out(9) <= nand_out(7) NAND nand_out(8); -- A AND B

    nand_out(10) <= nand_out(3) NAND CIN;        -- CIN AND (A XOR B)
    COUT <= nand_out(9) NAND nand_out(10);       -- Final COUT output

end nand_only;
