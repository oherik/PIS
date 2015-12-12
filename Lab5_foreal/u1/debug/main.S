; CC12 - GMV Cross C compiler (V 4.2)
; optimization: None
; Default Code generation: HCS12
* Compiler Default segment names
	SEGMENT	text
	SEGMENT	bss
	SEGMENT	data
	SEGMENT	rodata
	FILE	"C:/Users/Erik/Documents/GitHub/PIS/Lab5_foreal/u1/main.c"

;     1 | #include "ports.h"
;     2 | 
;     3 | #define	set(x, mask)	(x) = (x) | (mask)
;     4 | #define clear(x, mask)	(x) = (x) & ~(mask)
;     5 | 
;     6 | unsigned char ML4shadow = 0;
	SEGMENT	data
_ML4shadow:	FCB	$0
	EXPORT	_ML4shadow	[r,1]

;     7 | 
;     8 | void main(void){
	SEGMENT	rodata
;	locals:
;		'value' at 0,SP (Value: -2,SP)

;	No registers allocated

	SEGMENT	text
	EXPORT	_main	[r,2]
_main:

	LEAS	-2,SP
_2:
;     9 | 	int value;
;    10 | 	while(0){
	BRA	_3
;    11 | 		value = ML4IN;
	LDAB	$600
	CLRA
	STD	0,SP
;    12 | 		ML4shadow = value;
	LDD	0,SP
	STAB	_ML4shadow
;    13 | 		ML4OUT = value;
	LDD	0,SP
	STAB	$400
;    14 | 	}
	BRA	_2
_3:
;    15 | }
	LEAS	2,SP
	RTS
