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
;    24 | 
;    25 | void display_dec(unsigned int value){
	SEGMENT	rodata
;	parameters:
;		'value' at 14,SP (Value: 2,SP)
;	locals:
;		'digits' at 6,SP (Value: -6,SP)
;		'i' at 5,SP (Value: -7,SP)
;		'b' at 4,SP (Value: -8,SP)
;		'btmp' at 3,SP (Value: -9,SP)
;		'valuecpy' at 2,SP (Value: -10,SP)

;	Total scratch space: 2 (bytes)

;	No registers allocated

	SEGMENT	text
	EXPORT	_display_dec	[r,2]
_display_dec:

	LEAS	-12,SP
	LDD	14,SP
	STAB	2,SP
;    26 | 	unsigned char digits[6];
;    27 | 	unsigned char i,b,btmp;
;    28 | 	unsigned char valuecpy = value;
;    29 | 	for(i=0; i<6; i++){
	CLR	5,SP
_7:
	LDAB	5,SP
	CMPB	#6
	BCS	_9
	LBRA	_10
_8:
	INC	5,SP
	BRA	_7
_9:
;    30 | 		btmp = value%10;
	LDD	14,SP
	LDX	#$0A
	IDIV
	STAB	3,SP
;    31 | 		value=value/10;
	LDD	14,SP
	LDX	#$0A
	IDIV
	STX	14,SP
;    32 | 		b = valuecpy%10;
	LDAB	2,SP
	CLRA
	LDX	#$0A
	IDIVS
	STAB	4,SP
;    33 | 		valuecpy/=10;
	LDAB	#$0A
	SEX	B,X
	LDAB	2,SP
	CLRA
	IDIV
	TFR	X,B
	STAB	2,SP
;    34 | 		digits[5-i] = b;
	LEAX	6,SP
	LDAB	5,SP
	CLRA
	STD	0,SP
	LDD	#5
	SUBD	0,SP
	LEAX	D,X
	LDAB	4,SP
	STAB	0,X
;    35 | 	}
	LBRA	_8
_10:
;    36 | 	display_digits(digits);
	LEAX	6,SP
	PSHX
	JSR	_display_digits
	LEAS	2,SP
;    37 | }
	LEAS	12,SP
	RTS
