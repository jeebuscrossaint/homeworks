library ieee;
use ieee.std_logic_1164.all;
use work.AdderPackage.all;

entity Adder8_AmarnathPatelVHDL is
    port(
        A, B   : in  std_logic_vector(7 downto 0);  -- Changed vector order to standard downto format
        Cin    : in  std_logic;
        S      : out std_logic_vector(7 downto 0);
        Cout   : out std_logic
    );
end entity Adder8_AmarnathPatelVHDL;

architecture Structure of Adder8_AmarnathPatelVHDL is
    signal W : std_logic_vector(6 downto 0);  -- Updated to match downto format

begin
    -- Chain the adders to form an 8-bit adder
    F0: FullAdder_AmarnathPatelVHDL port map (A(0), B(0), Cin, W(0), S(0));
    F1: FullAdder_AmarnathPatelVHDL port map (A(1), B(1), W(0), W(1), S(1));
    F2: FullAdder_AmarnathPatelVHDL port map (A(2), B(2), W(1), W(2), S(2));
    F3: FullAdder_AmarnathPatelVHDL port map (A(3), B(3), W(2), W(3), S(3));
    F4: FullAdder_AmarnathPatelVHDL port map (A(4), B(4), W(3), W(4), S(4));
    F5: FullAdder_AmarnathPatelVHDL port map (A(5), B(5), W(4), W(5), S(5));
    F6: FullAdder_AmarnathPatelVHDL port map (A(6), B(6), W(5), W(6), S(6));
    F7: FullAdder_AmarnathPatelVHDL port map (A(7), B(7), W(6), Cout, S(7));
end architecture Structure;
