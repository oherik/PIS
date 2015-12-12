; CC12 - GMV Cross C compiler (V 4.2)
; optimization: None
; Default Code generation: HCS12
* Compiler Default segment names
	SEGMENT	text
	SEGMENT	bss
	SEGMENT	data
	SEGMENT	rodata
	FILE	"C:/Users/Erik/Documents/GitHub/PIS/Lab5/ML4/globals.c"

;     1 | #define	PVECSIZE	32
;     2 | 
;     3 | short	shortint;
	SEGMENT	bss
_shortint:	RMB	$2
	EXPORT	_shortint	[r,2]

;     4 | long	longint;
_longint:	RMB	$4
	EXPORT	_longint	[r,4]

;     5 | int	justint;
_justint:	RMB	$2
	EXPORT	_justint	[r,2]

;     6 | int	intvec[10];
_intvec:	RMB	$14
	EXPORT	_intvec	[r,20]

;     7 | 
;     8 | void do_nothing(void);
;     9 | int do_something(void);
;    10 | int result;
_result:	RMB	$2
	EXPORT	_result	[r,2]

;    11 | int result,low,high;
_low:	RMB	$2
	EXPORT	_low	[r,2]

_high:	RMB	$2
	EXPORT	_high	[r,2]

;    12 | int max(int,int);
;    13 | 
;    14 | int pvec[PVECSIZE];
_pvec:	RMB	$40
	EXPORT	_pvec	[r,64]

;    15 | int size;
_size:	RMB	$2
	EXPORT	_size	[r,2]

;    16 | 
;    17 | 
;    18 | struct{
;    19 | 	int s1;
;    20 | 	char	s2;
;    21 | 	char*	s3;
;    22 | 	} komplex;
_komplex:	RMB	$5
	EXPORT	_komplex	[r,5]

;    23 | 	
;    24 | void main(void){
	SEGMENT	rodata
;	locals:
;		'test1' at 4,SP (Value: -2,SP)
;		'test2' at 2,SP (Value: -4,SP)
;		'test3' at 0,SP (Value: -6,SP)

;	No registers allocated

	SEGMENT	text
	EXPORT	_main	[r,2]
_main:

	LEAS	-6,SP
;    25 | int test1;
;    26 | int test2;
;    27 | int test3;
;    28 | test1= 10;
	LDD	#$0A
	STD	4,SP
;    29 | test2 = 11;
	LDD	#$0B
	STD	2,SP
;    30 | test3 = 12;
	LDD	#$0C
	STD	0,SP
;    31 | do_nothing();
	JSR	_do_nothing
;    32 | result = do_something();
	JSR	_do_something
	STD	_result
;    33 | result = max(low,high);
	LDD	_high
	PSHD
	LDD	_low
	PSHD
	JSR	_max
	LEAS	4,SP
	STD	_result
;    34 | size = scalar(pvec, PVECSIZE);
	LDD	#$20
	PSHD
	LDX	#_pvec
	PSHX
	JSR	_scalar
	LEAS	4,SP
	STD	_size
;    35 | }
	LEAS	6,SP
	RTS
