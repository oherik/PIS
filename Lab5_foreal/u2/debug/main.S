; CC12 - GMV Cross C compiler (V 4.2)
; optimization: None
; Default Code generation: HCS12
* Compiler Default segment names
	SEGMENT	text
	SEGMENT	bss
	SEGMENT	data
	SEGMENT	rodata
	FILE	"C:/Users/Erik/Documents/GitHub/PIS/Lab5_foreal/u2/main.c"

;     1 | 
;     2 | void main(void){
;	locals:
;		'key' at 0,SP (Value: -1,SP)

;	No registers allocated

	SEGMENT	text
	EXPORT	_main	[r,2]
_main:

	LEAS	-1,SP
_2:
	JSR	_get_key
	STAB	0,SP
;     3 | while(1){
;     4 | 	char key = get_key();
;     5 | 	display_dec(key);
	LDAB	0,SP
	PSHB
	JSR	_display_dec
	LEAS	1,SP
;     6 | 	}
	BRA	_2
_3:
;     7 | }
	LEAS	1,SP
	RTS
