//2. Generate a 4KHz wave with 60% duty cycle and also for 40 % duty cycle.

#include"lpc214x.h"

void PLL_init(void);
void PWM_init(void);

int main()
{
	PLL_init();
	PWM_init();
	while(1)
	{
		
		PWMMR1=9000;
		PWMMR2=6000;
		PWMLER=(1<<1)|(1<<2);
	}

}

void PLL_init()
{
	PLL0CON=0x01;
	PLL0CFG=0x24;
	PLL0FEED=0xAA;
	PLL0FEED=0x55;
	while((PLL0STAT & (1<<10))==0);
	PLL0CON=0x02;
	PLL0FEED=0xAA;
	PLL0FEED=0x55;
	VPBDIV=0x01;
}
void PWM_init()
{
	  PINSEL0=0x0008002;
	  PWMMR0=15000;
	  PWMTCR=0x09;
	  PWMMCR=0x02;
	  PWMPR=0;
	  PWMPCR=(1<<9)|(1<<10);
}

