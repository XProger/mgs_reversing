	opt	c+, at+, e+, n-
	section overlay.text

	xdef s01a_fadeio_800E0E08
s01a_fadeio_800E0E08:
	dw 0x27BDFFE8 ; 800E0E08
	dw 0xAFBF0010 ; 800E0E0C
	dw 0x8C840024 ; 800E0E10
	dw 0x00000000 ; 800E0E14
	dw 0x10800003 ; 800E0E18
	dw 0x00000000 ; 800E0E1C
	dw 0x0C005895 ; 800E0E20
	dw 0x00000000 ; 800E0E24
	dw 0x8FBF0010 ; 800E0E28
	dw 0x00000000 ; 800E0E2C
	dw 0x03E00008 ; 800E0E30
	dw 0x27BD0018 ; 800E0E34
