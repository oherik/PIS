typedef unsigned long int time_type;
void init_clock(void);
void clock_inter(void);
time_type get_time(void);
void hold(time_type);

typedef struct sCRG{
volatile unsigned char synr;
volatile unsigned char refdv;
volatile unsigned char ctflg;
volatile unsigned char crgflg;
}CRG;
