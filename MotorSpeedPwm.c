//4. DC motor is connected PWM5 and need to control the speed of it by operating switches at 
//P0.1/2/3/4 . write C program for the same.

#include"lpc214x.h"

void PLL_init(void);
void PWM_init(void);

int main()
{
	PLL_init();
	PWM_init();
	IO0DIR=0x00;
	while(1)
	{
		if(!(IO0PIN & (1<<1)))
		{
			PWMMR5=15000;
			PWMLER=(1<<5);
		}
		else if(!(IO0PIN & (1<<2)))
		{
			PWMMR5=30000;
			PWMLER=(1<<5);
		}
		else if(!(IO0PIN & (1<<3)))
		{
			PWMMR5=45000;
			PWMLER=(1<<5);
		}
		else if(!(IO0PIN & (1<<4)))
		{
			PWMMR5=60000;
			PWMLER=(1<<5);
		}
		else
		{
			PWMMR5=0;
			PWMLER=(1<<5);
		}
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
	  PINSEL1=0x0400;
	  PWMMR0=60000;
	  PWMTCR=0x09;
	  PWMMCR=0x02;
	  PWMPR=0;
	  PWMPCR=(1<<13);
}
