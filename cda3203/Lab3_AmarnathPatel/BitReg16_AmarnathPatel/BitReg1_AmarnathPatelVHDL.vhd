library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity BitReg1_AmarnathPatelVHDL is
    Port ( 
        clk : in STD_LOGIC;
        load : in STD_LOGIC;
        d : in STD_LOGIC;
        q : out STD_LOGIC
    );
end BitReg1_AmarnathPatelVHDL;

architecture Behavioral of BitReg1_AmarnathPatelVHDL is
    signal mux_out : STD_LOGIC;
    signal dff_out : STD_LOGIC;
begin
    -- Multiplexer
    mux_out <= d when load = '1' else dff_out;

    -- D-type Flip-Flop
    process(clk)
    begin
        if rising_edge(clk) then
            dff_out <= mux_out;
        end if;
    end process;

    q <= dff_out;
end Behavioral;