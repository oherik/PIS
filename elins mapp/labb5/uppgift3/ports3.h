typedef unsigned char * port8ptr;

#define ML4OUT_ADDRESS	0x400
#define ML4OUT *((port8ptr)ML4OUT_ADDRESS)

#define ML4IN_ADDRESS	0x600
#define	ML4IN *((port8ptr)ML4IN_ADDRESS)

#define ML15MODE_ADDRESS	0x9c2
#define	ML15MODE *((port8ptr)ML15MODE_ADDRESS)

#define ML15DATA_ADDRESS	0x9c3
#define	ML15DATA *((port8ptr)ML15DATA_ADDRESS)

//läsa av tangentbordet
#define ML2IN_ADDRESS	0x9c0
#define	ML2IN *((port8ptr)ML2IN_ADDRESS)

//alla klockadresser

//skriv till register
#define	SYNR_ADDRESS	0x34
#define	SYNR *((port8ptr)SYNR_ADDRESS)

//flags register
#define	CRGFLG_ADDRESS	0x37
#define	CRGFLG *((port8ptr)CRGFLG_ADDRESS)

//aktivera avbrott från kretsen, bit 7
#define	CRGINT_ADDRESS	0x38
#define	CRGINT *((port8ptr)CRGINT_ADDRESS)

//RTI control register
#define	RTICLT_ADDRESS	0x3B
#define	RTICLT *((port8ptr)RTICLT_ADDRESS)

typedef  void (*vec) (void);	//avbrottsvektor
typedef vec *vecptr;		//pekare till avbrottsvektor

#define	CLOCK_VEC_ADR	0x3FF0
#define	CLOCK_VEC		*((vecptr) CLOCK_VEC_ADR)

#define	IRQ_VEC_ADR	0x3FF2
#define	IRQ_VEC		*((vecptr) IRQ_VEC_ADR)


