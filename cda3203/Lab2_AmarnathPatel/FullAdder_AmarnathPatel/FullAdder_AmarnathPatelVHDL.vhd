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
    -- Intermediate NAND calculations
    nand_out(0) <= A NAND B;                     -- NAND of A and B
    nand_out(1) <= A NAND nand_out(0);           -- NAND of A and NAND_AB
    nand_out(2) <= B NAND nand_out(0);           -- NAND of B and NAND_AB
    nand_out(3) <= nand_out(1) NAND nand_out(2); -- Intermediate result for SUM

    nand_out(4) <= nand_out(3) NAND CIN;        -- Adding CIN to the SUM part
    nand_out(5) <= nand_out(3) NAND nand_out(4); -- Final SUM logic
    nand_out(6) <= CIN NAND nand_out(4);         -- COUT part logic
    SUM <= nand_out(5) NAND nand_out(6);         -- Final SUM output

    COUT <= nand_out(0) NAND nand_out(4);        -- Final COUT output
end nand_only;
