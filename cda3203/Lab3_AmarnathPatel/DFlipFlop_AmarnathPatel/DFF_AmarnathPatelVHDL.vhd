--- dff positive edge triggered
--- behavioural vhdl model

LIBRARY ieee;
USE ieee.std_logic_1164.all;

entity DFF_AmarnathPatelVHDL is
	port(
		D, clk	: in std_logic;
		Q		: out std_logic
	);
end DFF_AmarnathPatelVHDL;

architecture ABC of DFF_AmarnathPatelVHDL is
	SIGNAL tmp_q	:	std_logic := '0';
BEGIN
	process (clk)
	begin
		if rising_edge(clk) then
			tmp_q <= D;
		end if;
	end process;

	Q <= tmp_q;
END ABC;