	opt	c+, at+, e+, n-
	section overlay.text

	xdef s02c_800DDCAC
s02c_800DDCAC:
	dw 0x27BDFFE8 ; 800DDCAC
	dw 0xAFBF0014 ; 800DDCB0
	dw 0xAFB00010 ; 800DDCB4
	dw 0x8C900024 ; 800DDCB8
	dw 0x00000000 ; 800DDCBC
	dw 0x12000005 ; 800DDCC0
	dw 0x00000000 ; 800DDCC4
	dw 0x0C0060B8 ; 800DDCC8
	dw 0x02002021 ; 800DDCCC
	dw 0x0C006F01 ; 800DDCD0
	dw 0x02002021 ; 800DDCD4
	dw 0x8FBF0014 ; 800DDCD8
	dw 0x8FB00010 ; 800DDCDC
	dw 0x03E00008 ; 800DDCE0
	dw 0x27BD0018 ; 800DDCE4
