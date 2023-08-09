#include<lpc214x.h>

void PLL(void) {
  PLL0CON = 0x01;
	PLL0CFG = 0x24;
	PLL0FEED =  0xAA;
	PLL0FEED = 0x55;
	while((PLL0STAT & (1<<10))==0);
	PLL0CON = 0x03;
	PLL0FEED =  0xAA;
	PLL0FEED = 0x55;
	VPBDIV = 0x01;
}

void timer(unsigned int T_delay ,unsigned int unit) {
    T0CTCR = 0x00;
    T0PR = (unit)-1;	//60M / 60MHz  =1Hz
    T0TCR = 0x02;//reset
    T0TCR = 0x01;//enable
    while (T0TC != T_delay);
	  T0TCR = 0x0;
	  T0TC= 0;	
}

int main() {
    PINSEL0 = 0xF;
    IO0DIR = 0xF;
    PLL();
    while (1) {		
        timer(5,60e5);//function call for 0.5s delay
    IO0CLR = (1<<2);
		IO0SET = (1<<0);
        timer(2,60e3);//function call for 2ms delay
		IO0CLR = (1<<0); 
    IO0SET = (1<<1) ;
		timer(3,60e6);//function call for 3s delay
		IO0CLR = (1<<1);
		IO0SET = (1<<2);
    }
}
