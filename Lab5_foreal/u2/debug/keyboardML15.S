; CC12 - GMV Cross C compiler (V 4.2)
; optimization: None
; Default Code generation: HCS12
* Compiler Default segment names
	SEGMENT	text
	SEGMENT	bss
	SEGMENT	data
	SEGMENT	rodata
	FILE	"C:/Users/Erik/Documents/GitHub/PIS/Lab5_foreal/u2/keyboardML15.c"

;     1 | #include "keyboardML15.h"
;     2 | #include "ports.h"
;     3 | #define clear(x, mask)	(x) &= ~(mask)
;     4 | 
;     5 | char get_key(void){
;	locals:
;		'tmp' at 1,SP (Value: -1,SP)
;		'key' at 0,SP (Value: -2,SP)

;	No registers allocated

	SEGMENT	text
	EXPORT	_get_key	[r,2]
_get_key:

	LEAS	-2,SP
	LDAB	$9C0
	STAB	0,SP
_2:
;     6 | 	char tmp;
;     7 | 	char key = ML15IN;		//Läs in fråm ML2
;     8 | 	while(key<0){			//key kommer vara >0 när en tangent finns tillgänglig
	TST	0,SP
	BGE	_3
;     9 | 		key = ML15IN;	
	LDAB	$9C0
	STAB	0,SP
;    10 | 	}
	BRA	_2
_3:
;    11 | 	tmp = ML15IN;
	LDAB	$9C0
	STAB	1,SP
_4:
;    12 | 	while(tmp>=0){
	TST	1,SP
	BLT	_5
;    13 | 		tmp = ML15IN;
	LDAB	$9C0
	STAB	1,SP
;    14 | 	}				//Busy wait tills personen släppt knappen
	BRA	_4
_5:
;    15 | 	clear(key, 0xF0);		//Tangenten ligger i bit 0-3
	LDAB	#$0F
	ANDB	0,SP
	STAB	0,SP
;    16 | 	return key;	
	LDAB	0,SP
	BRA	_6
_6:
;    17 | }
	LEAS	2,SP
	RTS
