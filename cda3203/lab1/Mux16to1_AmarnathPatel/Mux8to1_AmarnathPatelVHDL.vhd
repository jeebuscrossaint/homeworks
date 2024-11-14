library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Mux8to1_AmarnathPatelVHDL is
    Port(
        sel : in STD_LOGIC_VECTOR(2 downto 0);  -- 3 selection bits
        in0 : in STD_LOGIC;                     -- Input 0
        in1 : in STD_LOGIC;                     -- Input 1
        in2 : in STD_LOGIC;                     -- Input 2
        in3 : in STD_LOGIC;                     -- Input 3
        in4 : in STD_LOGIC;                     -- Input 4
        in5 : in STD_LOGIC;                     -- Input 5
        in6 : in STD_LOGIC;                     -- Input 6
        in7 : in STD_LOGIC;                     -- Input 7
        output : out STD_LOGIC                  -- Output
    );
end Mux8to1_AmarnathPatelVHDL;

architecture structural of Mux8to1_AmarnathPatelVHDL is
    -- Component declarations
    component Mux4to1_AmarnathPatelVHDL is
        Port(
            sel : in STD_LOGIC_VECTOR(1 downto 0);
            in0 : in STD_LOGIC;
            in1 : in STD_LOGIC;
            in2 : in STD_LOGIC;
            in3 : in STD_LOGIC;
            output : out STD_LOGIC
        );
    end component;
    
    component Mux2to1_AmarnathPatelVHDL is
        Port(
            s : in STD_LOGIC;
            x : in STD_LOGIC;
            y : in STD_LOGIC;
            mux : out STD_LOGIC
        );
    end component;
    
    -- Internal signals for intermediate MUX outputs
    signal mux4to1_out1 : STD_LOGIC;
    signal mux4to1_out2 : STD_LOGIC;
    
begin
    -- First 4-to-1 MUX for inputs 0-3
    MUX4_1: Mux4to1_AmarnathPatelVHDL
        port map(
            sel => sel(1 downto 0),
            in0 => in0,
            in1 => in1,
            in2 => in2,
            in3 => in3,
            output => mux4to1_out1
        );
        
    -- Second 4-to-1 MUX for inputs 4-7
    MUX4_2: Mux4to1_AmarnathPatelVHDL
        port map(
            sel => sel(1 downto 0),
            in0 => in4,
            in1 => in5,
            in2 => in6,
            in3 => in7,
            output => mux4to1_out2
        );
        
    -- Final 2-to-1 MUX to select between the two 4-to-1 MUX outputs
    MUX2_FINAL: Mux2to1_AmarnathPatelVHDL
        port map(
            s => sel(2),
            x => mux4to1_out1,
            y => mux4to1_out2,
            mux => output
        );
        
end structural;