	opt	c+, at+, e+, n-
	section overlay.text

	xdef s01a_blink_tx_800DD3D4
s01a_blink_tx_800DD3D4:
	dw 0x27BDFFE8 ; 800DD3D4
	dw 0xAFBF0014 ; 800DD3D8
	dw 0xAFB00010 ; 800DD3DC
	dw 0x8C820034 ; 800DD3E0
	dw 0x00000000 ; 800DD3E4
	dw 0x8C420000 ; 800DD3E8
	dw 0x00000000 ; 800DD3EC
	dw 0x30500003 ; 800DD3F0
	dw 0x12000008 ; 800DD3F4
	dw 0x00000000 ; 800DD3F8
	dw 0x0C0374D6 ; 800DD3FC
	dw 0x00000000 ; 800DD400
	dw 0x00401821 ; 800DD404
	dw 0x10600004 ; 800DD408
	dw 0x00001021 ; 800DD40C
	dw 0x08037507 ; 800DD410
	dw 0x02001021 ; 800DD414
	dw 0x00001021 ; 800DD418
	dw 0x8FBF0014 ; 800DD41C
	dw 0x8FB00010 ; 800DD420
	dw 0x03E00008 ; 800DD424
	dw 0x27BD0018 ; 800DD428
