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
