	opt	c+, at+, e+, n-
	section overlay.text

	xdef s03c_otacom_800CB0F0
s03c_otacom_800CB0F0:
	dw 0x3C06800C ; 800CB0F0
	dw 0x90C333B4 ; 800CB0F4
	dw 0x24020006 ; 800CB0F8
	dw 0x1062000B ; 800CB0FC
	dw 0x00803821 ; 800CB100
	dw 0x00001021 ; 800CB104
	dw 0x3C03800D ; 800CB108
	dw 0x90C533B4 ; 800CB10C
	dw 0x24637F3C ; 800CB110
	dw 0x00052080 ; 800CB114
	dw 0x00832021 ; 800CB118
	dw 0x24A50001 ; 800CB11C
	dw 0xAC870000 ; 800CB120
	dw 0x03E00008 ; 800CB124
	dw 0xA0C533B4 ; 800CB128
	dw 0x03E00008 ; 800CB12C
	dw 0x2402FFFF ; 800CB130
