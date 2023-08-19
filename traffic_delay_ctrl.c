/* Implement a simple traffic light controller, you would need to configure timers.
  to control the green light with 29s delay, yellow light with 1s delay and red light with 60s delay. */

#include<lpc214x.h>

#define Green_delay 29   //29s  but while verifying on keil keep delay 1s only else u need to wait to long
#define Red_delay 1  //1s 
#define Yellow_delay 60 //60s 

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
		T0TCR = 0x0;
		T0TC= 0;	

}

int main() {
    PINSEL0 = 0x00;
    IO0DIR = 0xFF;
    PLL();
    while (1) {
		IO0CLR = (1<<1); 
        IO0SET = (1<<0) ;  //green light
        timer(Green_delay);
		IO0CLR = (1<<0); 
        IO0SET = (1<<1) ;//yellow light
		timer(Yellow_delay);
		IO0CLR = (1<<1);
		IO0SET = (1<<2); //red light
		timer(Red_delay);
		IO0CLR = (1<<2);
    }
}
