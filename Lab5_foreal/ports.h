#define	ML4IN_ADDRESS	0x600
#define	ML4OUT_ADDRESS	0x400

typdef	unsigned char * port8ptr;

#define	ML4IN	*((port8ptr) ML4IN_ADDRESS)
#define	ML4OUT*((port8ptr) ML4OUT_ADDRESS)