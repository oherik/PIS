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
;     2 | 
;     3 | #define	set(x, mask)	(x) = (x) | (mask)
;     4 | #define clear(x, mask)	(x) = (x) & ~(mask)
;     5 | 
;     6 | char get_key(void){
;	locals:
;		'key' at 0,SP (Value: -1,SP)

;	No registers allocated

	SEGMENT	text
	EXPORT	_get_key	[r,2]
_get_key:

	LEAS	-1,SP
	LDAB	$9C0
	STAB	0,SP
_2:
;     7 | 	char key = ML15IN;
;     8 | 	while(key<=0){
	TST	0,SP
	BGT	_3
;     9 | 		key = ML15IN;	
	LDAB	$9C0
	STAB	0,SP
;    10 | 	}
	BRA	_2
_3:
;    11 | 	clear(key, 0xF0);
	LDAB	0,SP
	SEX	B,D
	ANDB	#$0F
	STAB	0,SP
;    12 | 	return key;	
	LDAB	0,SP
	BRA	_4
_4:
;    13 | }
	LEAS	1,SP
	RTS
;    14 | 
;    15 | void main(void){
	SEGMENT	rodata

;	No registers allocated

	SEGMENT	text
	EXPORT	_main	[r,2]
_main:

;    16 |  
;    17 | }
	RTS
