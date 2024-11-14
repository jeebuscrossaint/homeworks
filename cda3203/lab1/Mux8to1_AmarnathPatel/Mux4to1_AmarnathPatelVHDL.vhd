library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Mux4to1_AmarnathPatelVHDL is
    Port(
        sel : in STD_LOGIC_VECTOR(1 downto 0);  -- 2 selection bits
        in0 : in STD_LOGIC;                     -- Input 0
        in1 : in STD_LOGIC;                     -- Input 1
        in2 : in STD_LOGIC;                     -- Input 2
        in3 : in STD_LOGIC;                     -- Input 3
        output : out STD_LOGIC                  -- Output
    );
end Mux4to1_AmarnathPatelVHDL;

architecture structural of Mux4to1_AmarnathPatelVHDL is
    -- Component declaration for 2-to-1 MUX
    component Mux2to1_AmarnathPatelVHDL is
        Port(
            s : in STD_LOGIC;
            x : in STD_LOGIC;
            y : in STD_LOGIC;
            mux : out STD_LOGIC
        );
    end component;
    
    -- Internal signals for intermediate MUX outputs
    signal mux1_out : STD_LOGIC;
    signal mux2_out : STD_LOGIC;
    
begin
    -- First level of 2-to-1 MUXes
    MUX1: Mux2to1_AmarnathPatelVHDL
        port map(
            s => sel(0),
            x => in0,
            y => in1,
            mux => mux1_out
        );
        
    MUX2: Mux2to1_AmarnathPatelVHDL
        port map(
            s => sel(0),
            x => in2,
            y => in3,
            mux => mux2_out
        );
        
    -- Final 2-to-1 MUX
    MUX3: Mux2to1_AmarnathPatelVHDL
        port map(
            s => sel(1),
            x => mux1_out,
            y => mux2_out,
            mux => output
        );
        
end structural;