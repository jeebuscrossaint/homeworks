library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;

entity ProgramCounter_AmarnathPatelVHDL is
    Port ( 
        d : in STD_LOGIC_VECTOR(15 downto 0);
        load, inc, reset, clock : in STD_LOGIC;  
        q : out STD_LOGIC_VECTOR(15 downto 0)
    );
end ProgramCounter_AmarnathPatelVHDL;

architecture abc of ProgramCounter_AmarnathPatelVHDL is
    signal q_internal : STD_LOGIC_VECTOR(15 downto 0);
begin
    process(clock)
    begin
        if reset = '1' then
            q_internal <= (others => '0');
        elsif rising_edge(clock) then
            if load = '1' then
                q_internal <= d;
            elsif inc = '1' then
                q_internal <= q_internal + 1;
            end if;
        end if;
    end process;
    q <= q_internal;

end abc;