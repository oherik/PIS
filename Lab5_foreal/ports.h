#define	ML4IN	0x600
#define	ML4OUT	0x400

typdef	unsigned char * port8ptr;

#define	ML4READ	*((port8ptr) ML4IN)
#define	ML4WRITE *((port8ptr) ML4OUT)