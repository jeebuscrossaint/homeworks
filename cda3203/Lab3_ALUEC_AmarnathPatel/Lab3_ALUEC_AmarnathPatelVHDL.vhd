library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity Lab3_ALUEC_AmarnathPatelVHDL is
    port (
        x, y: in std_logic_vector(15 downto 0);
        zx, nx, zy, ny, f, no: in std_logic;
        result: out std_logic_vector(15 downto 0);
        zr, ng: out std_logic
    );
end entity Lab3_ALUEC_AmarnathPatelVHDL;

architecture behavior of Lab3_ALUEC_AmarnathPatelVHDL is
    signal x_mod, y_mod: std_logic_vector(15 downto 0);
    signal result_tmp: std_logic_vector(15 downto 0);
begin
    x_mod <= (others => '0') when zx = '1' else (not x) when nx = '1' else x;
    y_mod <= (others => '0') when zy = '1' else (not y) when ny = '1' else y;

    result_tmp <= std_logic_vector(signed(x_mod) + signed(y_mod)) when f = '1' else std_logic_vector(signed(x_mod) and signed(y_mod));

    result <= result_tmp when no = '0' else (not result_tmp);

    zr <= '1' when result_tmp = (15 downto 0 => '0') else '0';
    ng <= result_tmp(15);
end architecture behavior;