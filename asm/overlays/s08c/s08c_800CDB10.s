	opt	c+, at+, e+, n-
	section overlay.text

	xdef s08c_800CDB10
s08c_800CDB10:
	dw 0x24A5FFFF ; 800CDB10
	dw 0x04A0000E ; 800CDB14
	dw 0x00801021 ; 800CDB18
	dw 0x3C070400 ; 800CDB1C
	dw 0x3C06E100 ; 800CDB20
	dw 0x34C60220 ; 800CDB24
	dw 0x3C034280 ; 800CDB28
	dw 0x346380FF ; 800CDB2C
	dw 0x24840008 ; 800CDB30
	dw 0xAC470000 ; 800CDB34
	dw 0xAC86FFFC ; 800CDB38
	dw 0xAC830000 ; 800CDB3C
	dw 0x24840014 ; 800CDB40
	dw 0x24A5FFFF ; 800CDB44
	dw 0x04A1FFFA ; 800CDB48
	dw 0x24420014 ; 800CDB4C
	dw 0x03E00008 ; 800CDB50
	dw 0x00000000 ; 800CDB54
