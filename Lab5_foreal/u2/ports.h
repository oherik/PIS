typedef	unsigned char port8;
typedef	port8 * port8ptr;
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

