	opt	c+, at+, e+, n-
	section overlay.text

	xdef d00a_800CADA0
d00a_800CADA0:
	dw 0x27BDFFE0 ; 800CADA0
	dw 0xAFB00010 ; 800CADA4
	dw 0x00808021 ; 800CADA8
	dw 0xAFB10014 ; 800CADAC
	dw 0x26110BE0 ; 800CADB0
	dw 0xAFBF0018 ; 800CADB4
	dw 0x82040BA0 ; 800CADB8
	dw 0x0C03439E ; 800CADBC
	dw 0x02202821 ; 800CADC0
	dw 0x8E02004C ; 800CADC4
	dw 0x02202821 ; 800CADC8
	dw 0x8C440008 ; 800CADCC
	dw 0x0C0171B1 ; 800CADD0
	dw 0x2406FFFF ; 800CADD4
	dw 0x8E03004C ; 800CADD8
	dw 0xAE020BF4 ; 800CADDC
	dw 0x8C620000 ; 800CADE0
	dw 0x00000000 ; 800CADE4
	dw 0xAE020BF8 ; 800CADE8
	dw 0x8FBF0018 ; 800CADEC
	dw 0x8FB10014 ; 800CADF0
	dw 0x8FB00010 ; 800CADF4
	dw 0x03E00008 ; 800CADF8
	dw 0x27BD0020 ; 800CADFC
