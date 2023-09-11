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

void timer(unsigned int T_delay) {
    T0CTCR = 0x00;
    T0PR = 60e6-1;	//60M / 60MHz  =1Hz
    T0TCR = 0x02;
    T0TCR = 0x01;
    while (T0TC != T_delay);
	if(T_delay == 3)
	{
		T0TCR = 0x0;
		T0TC= 0;	
	}
	else
	{
    T0TCR = 0x0;
	}
}

int main() {
    PINSEL0 = 0xFF;
    IO0DIR = 0xFF;
    PLL();
    while (1) {
		IO0CLR = (1<<2);
        IO0SET = (1<<0);
        timer(1);//level 1
		IO0CLR = (1<<0); 
        IO0SET = (1<<1) ;
        timer(2);//level 2
		IO0CLR = (1<<1);
		IO0SET = (1<<2);
		timer(3);//level 3
    }
}
