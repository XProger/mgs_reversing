	opt	c+, at+, e+, n-
	section overlay.text

	xdef d00a_800DDEE8
d00a_800DDEE8:
	dw 0x24020010 ; 800DDEE8
	dw 0xAC820058 ; 800DDEEC
	dw 0xAC82005C ; 800DDEF0
	dw 0x00001021 ; 800DDEF4
	dw 0xAC850024 ; 800DDEF8
	dw 0xAC86004C ; 800DDEFC
	dw 0xAC870050 ; 800DDF00
	dw 0x03E00008 ; 800DDF04
	dw 0xAC870054 ; 800DDF08
