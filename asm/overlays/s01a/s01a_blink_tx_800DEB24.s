	opt	c+, at+, e+, n-
	section overlay.text

	xdef s01a_blink_tx_800DEB24
s01a_blink_tx_800DEB24:
	dw 0x27BDFFE8 ; 800DEB24
	dw 0xAFBF0014 ; 800DEB28
	dw 0xAFB00010 ; 800DEB2C
	dw 0x8C900020 ; 800DEB30
	dw 0x00000000 ; 800DEB34
	dw 0x12000005 ; 800DEB38
	dw 0x00000000 ; 800DEB3C
	dw 0x0C0060B8 ; 800DEB40
	dw 0x02002021 ; 800DEB44
	dw 0x0C006F01 ; 800DEB48
	dw 0x02002021 ; 800DEB4C
	dw 0x8FBF0014 ; 800DEB50
	dw 0x8FB00010 ; 800DEB54
	dw 0x03E00008 ; 800DEB58
	dw 0x27BD0018 ; 800DEB5C
