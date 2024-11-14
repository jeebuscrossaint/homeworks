LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.all;

PACKAGE AdderPackage IS

-- add components
COMPONENT NAND3_AmarnathPatelVHDL IS
	PORT(X0,X1,X2:IN STD_LOGIC;
			f	 :OUT STD_LOGIC);
END COMPONENT NAND3_AmarnathPatelVHDL;

COMPONENT NAND4_AmarnathPatelVHDL IS
	PORT(X0,X1,X2,X3:IN STD_LOGIC;
			f		:OUT STD_LOGIC);
END COMPONENT NAND4_AmarnathPatelVHDL;

COMPONENT FullAdder_AmarnathPatelVHDL is
    port (
        A, B, CIN : in STD_LOGIC;
        SUM, COUT : out STD_LOGIC
    );
END COMPONENT FullAdder_AmarnathPatelVHDL;

END PACKAGE AdderPackage;