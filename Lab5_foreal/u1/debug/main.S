; CC12 - GMV Cross C compiler (V 4.2)
; optimization: None
; Default Code generation: HCS12
* Compiler Default segment names
	SEGMENT	text
	SEGMENT	bss
	SEGMENT	data
	SEGMENT	rodata
	FILE	"C:/Users/Erik/Documents/GitHub/PIS/Lab5_foreal/u1/main.c"

;     1 | #define	set(x, mask)	(x) = (x) | (mask)
;     2 | #define clear(x, mask)	(x) = (x) & ~(mask)
;     3 | 
;     4 | unsigned char	ML4shadow = 0;
	SEGMENT	data
_ML4shadow:	FCB	$0
	EXPORT	_ML4shadow	[r,1]

;     5 | 
;     6 | void main(void){
	SEGMENT	rodata

;	No registers allocated

	SEGMENT	text
	EXPORT	_main	[r,2]
_main:

;     7 | }
	RTS
