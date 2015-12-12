#define	PVECSIZE	32

short	shortint;
long	longint;
int	justint;
int	intvec[10];

void do_nothing(void);
int do_something(void);
int result;
int result,low,high;
int max(int,int);

int pvec[PVECSIZE];
int size;


struct{
	int s1;
	char	s2;
	char*	s3;
	} komplex;
	
void main(void){
int test1;
int test2;
int test3;
test1= 10;
test2 = 11;
test3 = 12;
do_nothing();
result = do_something();
result = max(low,high);
size = scalar(pvec, PVECSIZE);
}