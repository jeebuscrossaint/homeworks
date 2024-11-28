library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity RegisterRam8_AmarnathPatelVHDL is 
	port(
		D :	IN STD_LOGIC_VECTOR(15 downto 0);
		ld, clk	: IN STD_LOGIC;
		addr : IN STD_LOGIC_VECTOR(2 downto 0);
		Q : OUT STD_LOGIC_VECTOR(15 downto 0)
		);
end entity RegisterRam8_AmarnathPatelVHDL;

architecture abc of RegisterRam8_AmarnathPatelVHDL is
	type Array6x16 is array (7 downto 0) of std_logic_vector(15 downto 0);
	signal RAM : Array6x16;
	signal index : integer range 0 to 7;

begin
	process(clk)
	begin
		if rising_edge(clk) then
			index <= to_integer(unsigned(addr));
			if ld = '1' then
				RAM(index) <= D;
			else
				Q <= RAM(index);
			end if;
		end if;
	end process;
end architecture abc;