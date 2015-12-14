typedef	unsigned char port8;
typedef	unsigned int port16;
typedef	port8 * port8ptr;
typedef	port16 * port16ptr;
typedef void (*vec)(void);
typedef vec *vecptr;

//Avbrott
#define IRQ_VEC_ADR	0x3ff0
#define IRQ_VEC		*((vecptr) IRQ_VEC_ADR)

//Klocka
#define CLOCK_ADR	0x3ff0
#define CLOCK		*((port8ptr) CLOCK_ADR)

#define CRGINT_ADR	CLOCK_ADR+4
#define	CRGINT		*((port8ptr) CRGINT_ADR)

#define CRGFLG_ADR	CLOCK_ADR+3
#define	CRGFLG		*((port8ptr) CRGFLG_ADR)

#define RTICTL_ADR	CLOCK_ADR+7
#define	RTICTL		*((port8ptr) RTICTL_ADR)




//Ml4
#define	ML4IN_ADDRESS	0x600
#define	ML4OUT_ADDRESS	0x400

#define	ML4IN	*((port8ptr) ML4IN_ADDRESS)
#define	ML4OUT	*((port8ptr) ML4OUT_ADDRESS)

//Keyboard in
#define KEYDECODE_ADDRESS 0x9C0
#define ML15IN 	*((port8ptr) KEYDECODE_ADDRESS) 

//Display out
#define DISPLAYMODE_ADDRESS 0x9C2
#define DISPLAYDATA_ADDRESS 0x9C3
#define ML15MODE 	*((port8ptr) DISPLAYMODE_ADDRESS) 
#define ML15DATA 	*((port8ptr) DISPLAYDATA_ADDRESS)

