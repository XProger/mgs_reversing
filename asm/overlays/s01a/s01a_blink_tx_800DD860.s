	opt	c+, at+, e+, n-
	section overlay.text

	xdef s01a_blink_tx_800DD860
s01a_blink_tx_800DD860:
	dw 0x27BDFFD8 ; 800DD860
	dw 0xAFB20018 ; 800DD864
	dw 0x00809021 ; 800DD868
	dw 0xAFB10014 ; 800DD86C
	dw 0xAFBF0020 ; 800DD870
	dw 0xAFB3001C ; 800DD874
	dw 0xAFB00010 ; 800DD878
	dw 0x86500C0A ; 800DD87C
	dw 0x14A0001F ; 800DD880
	dw 0x26510020 ; 800DD884
	dw 0x86420DFC ; 800DD888
	dw 0x00000000 ; 800DD88C
	dw 0x14400007 ; 800DD890
	dw 0x2644009C ; 800DD894
	dw 0x24020001 ; 800DD898
	dw 0xAE420BE0 ; 800DD89C
	dw 0x3C02800C ; 800DD8A0
	dw 0x84453CE6 ; 800DD8A4
	dw 0x0803763E ; 800DD8A8
	dw 0x00003021 ; 800DD8AC
	dw 0x86430DFE ; 800DD8B0
	dw 0x00000000 ; 800DD8B4
	dw 0x04610008 ; 800DD8B8
	dw 0x00003021 ; 800DD8BC
	dw 0x2644009C ; 800DD8C0
	dw 0x24020001 ; 800DD8C4
	dw 0xAE420BE0 ; 800DD8C8
	dw 0x3C02800C ; 800DD8CC
	dw 0x84453CE6 ; 800DD8D0
	dw 0x0803763E ; 800DD8D4
	dw 0x00000000 ; 800DD8D8
	dw 0x24630001 ; 800DD8DC
	dw 0x3C02800C ; 800DD8E0
	dw 0x24423CE4 ; 800DD8E4
	dw 0xAE430BE0 ; 800DD8E8
	dw 0x00031840 ; 800DD8EC
	dw 0x00621821 ; 800DD8F0
	dw 0x84650000 ; 800DD8F4
	dw 0x0C00D335 ; 800DD8F8
	dw 0x24070004 ; 800DD8FC
	dw 0x8E420BE0 ; 800DD900
	dw 0x24030001 ; 800DD904
	dw 0x14430010 ; 800DD908
	dw 0x00000000 ; 800DD90C
	dw 0x86420DFC ; 800DD910
	dw 0x00000000 ; 800DD914
	dw 0x10400016 ; 800DD918
	dw 0x2644009C ; 800DD91C
	dw 0x86420DFE ; 800DD920
	dw 0x00000000 ; 800DD924
	dw 0x00431021 ; 800DD928
	dw 0x3C03800C ; 800DD92C
	dw 0x24633CE4 ; 800DD930
	dw 0xAE420BE0 ; 800DD934
	dw 0x00021040 ; 800DD938
	dw 0x00431021 ; 800DD93C
	dw 0x84450000 ; 800DD940
	dw 0x0803765B ; 800DD944
	dw 0x00003021 ; 800DD948
	dw 0x86420DFC ; 800DD94C
	dw 0x00000000 ; 800DD950
	dw 0x14400007 ; 800DD954
	dw 0x2644009C ; 800DD958
	dw 0x00003021 ; 800DD95C
	dw 0x3C02800C ; 800DD960
	dw 0xAE430BE0 ; 800DD964
	dw 0x84453CE6 ; 800DD968
	dw 0x0C00D335 ; 800DD96C
	dw 0x24070004 ; 800DD970
	dw 0x06010007 ; 800DD974
	dw 0x3C02800E ; 800DD978
	dw 0x2442D798 ; 800DD97C
	dw 0xAE420BD0 ; 800DD980
	dw 0xAE400BD8 ; 800DD984
	dw 0xA6400070 ; 800DD988
	dw 0x08037689 ; 800DD98C
	dw 0xA640006C ; 800DD990
	dw 0xA630004E ; 800DD994
	dw 0x8E420BE0 ; 800DD998
	dw 0x00000000 ; 800DD99C
	dw 0x000218C0 ; 800DD9A0
	dw 0x00621821 ; 800DD9A4
	dw 0x00031880 ; 800DD9A8
	dw 0x24630C48 ; 800DD9AC
	dw 0x02439821 ; 800DD9B0
	dw 0x8E620000 ; 800DD9B4
	dw 0x00000000 ; 800DD9B8
	dw 0x18400019 ; 800DD9BC
	dw 0x00008821 ; 800DD9C0
	dw 0x02608021 ; 800DD9C4
	dw 0x86030004 ; 800DD9C8
	dw 0x86420186 ; 800DD9CC
	dw 0x00000000 ; 800DD9D0
	dw 0x1462000E ; 800DD9D4
	dw 0x00000000 ; 800DD9D8
	dw 0x86420E02 ; 800DD9DC
	dw 0x00000000 ; 800DD9E0
	dw 0x10400005 ; 800DD9E4
	dw 0x00000000 ; 800DD9E8
	dw 0x86050006 ; 800DD9EC
	dw 0x86060008 ; 800DD9F0
	dw 0x0C00CA71 ; 800DD9F4
	dw 0x26440020 ; 800DD9F8
	dw 0x8602000A ; 800DD9FC
	dw 0x9603000A ; 800DDA00
	dw 0x10400002 ; 800DDA04
	dw 0x00000000 ; 800DDA08
	dw 0xA6430E00 ; 800DDA0C
	dw 0x8E620000 ; 800DDA10
	dw 0x26310001 ; 800DDA14
	dw 0x0222102A ; 800DDA18
	dw 0x1440FFEA ; 800DDA1C
	dw 0x26100008 ; 800DDA20
	dw 0x8FBF0020 ; 800DDA24
	dw 0x8FB3001C ; 800DDA28
	dw 0x8FB20018 ; 800DDA2C
	dw 0x8FB10014 ; 800DDA30
	dw 0x8FB00010 ; 800DDA34
	dw 0x03E00008 ; 800DDA38
	dw 0x27BD0028 ; 800DDA3C
