#define	ML4IN	0x600
#define	ML4OUT	0x400

typdef	port	char *;

#define	ML4READ	*((port) ML4IN)
#define	ML4WRITE *((port) ML4OUT)