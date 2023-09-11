#include <lpc214x.h>

void PLL_init(void);
void Timer0_init(void);
__irq void timer0ISR(void);

int main(void){
    PLL_init();
    Timer0_init();
	PINSEL0=0x00000;   
    IO0DIR = (1<<10);  
    while(1);
}

void Timer0_init(void){
    T0CTCR = 0x0;       
    T0PR = (60e5)-1;            
    T0MR0 = 5;              
    T0MCR = (1<<0) | (1<<1);    // Set bit0 & bit1 to Interrupt & Reset TC on MR0
    VICVectAddr4 = (unsigned)timer0ISR;
    VICVectCntl4 = (1<<5) | 4;  
    VICIntEnable = (1<<4);       
    T0TCR = (1<<1);             // Reset Timer
}

__irq void timer0ISR(void){
	int i;
    long int readVal;
    readVal = T0IR;             
    IO0SET	= (1<<10); 
	for(i=0;i<100000;i++);  
	IO0CLR = (1<<10);       
    T0IR = readVal;             
    VICVectAddr = 0x0;         
}
void PLL_init(void){
    PLL0CON = 0x01;            
    PLL0CFG = 0x24;             
    PLL0FEED = 0xAA;            
    PLL0FEED = 0x55; 
    while(!(PLL0STAT & (1<<10))); 
    PLL0CON = 0x03;             
    PLL0FEED = 0xAA;           
    VPBDIV = 0x01;             
}
