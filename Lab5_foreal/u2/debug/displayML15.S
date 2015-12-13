; CC12 - GMV Cross C compiler (V 4.2)
; optimization: None
; Default Code generation: HCS12
* Compiler Default segment names
	SEGMENT	text
	SEGMENT	bss
	SEGMENT	data
	SEGMENT	rodata
	FILE	"C:/Users/Erik/Documents/GitHub/PIS/Lab5_foreal/u2/displayML15.c"

;     1 | #include "displayML15.h"
;     2 | #include "ports.h"
;     3 | #define	set(x, mask)	(x) |= (mask)
;     4 | #define clear(x, mask)	(x) &= ~(mask)
;     5 | 
;     6 | 
;     7 | void display_digits(unsigned char * digits){	//Ta in en pekare till arrayen
;	parameters:
;		'digits' at 3,SP (Value: 2,SP)
;	locals:
;		'i' at 0,SP (Value: -1,SP)

;	No registers allocated

	SEGMENT	text
	EXPORT	_display_digits	[r,2]
_display_digits:

	LEAS	-1,SP
;     8 | 	char i;
;     9 | 	
;    10 | 	//Initiate controller
;    11 | 	ML15MODE  = 1;
	LDAB	#1
	STAB	$9C2
;    12 | 	ML15DATA = 0x90;
	LDAB	#$90
	STAB	$9C3
;    13 | 	ML15MODE  = 0;
	CLR	$9C2
;    14 | 	
;    15 | 	//Display the digits
;    16 | 	for(i=0; i<6; i++){
	CLR	0,SP
_2:
	LDAB	0,SP
	CMPB	#6
	BLT	_4
	BRA	_5
_3:
	INC	0,SP
	BRA	_2
_4:
;    17 | 		ML15DATA = *digits;
	LDAB	[3,SP]
	STAB	$9C3
;    18 | 		digits++;			//Peka på nästa siffra
	LDX	3,SP
	INX
	STX	3,SP
;    19 | 	}
	BRA	_3
_5:
;    20 | 	ML15DATA = 0;
	CLR	$9C3
;    21 | 	ML15DATA = 0;
	CLR	$9C3
;    22 | 
;    23 | }
	LEAS	1,SP
	RTS
