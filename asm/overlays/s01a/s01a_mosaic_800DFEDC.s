	opt	c+, at+, e+, n-
	section overlay.text

	xdef s01a_mosaic_800DFEDC
s01a_mosaic_800DFEDC:
	dw 0x27BDFFE0 ; 800DFEDC
	dw 0x308400FF ; 800DFEE0
	dw 0xAFA50010 ; 800DFEE4
	dw 0x00002821 ; 800DFEE8
	dw 0x00A03021 ; 800DFEEC
	dw 0xAFBF0018 ; 800DFEF0
	dw 0x0C037F98 ; 800DFEF4
	dw 0x00A03821 ; 800DFEF8
	dw 0x8FBF0018 ; 800DFEFC
	dw 0x00000000 ; 800DFF00
	dw 0x03E00008 ; 800DFF04
	dw 0x27BD0020 ; 800DFF08
