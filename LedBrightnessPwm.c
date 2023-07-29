//3. Interface LED to P0.0 and write a c program to LED dimming using PWM. Such that switch at 
//P0.1 pressed = 25 % bright , P0.2 = 50% , P0.3= 75% and P0.4 gives full brightness.

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
			PWMMR1=15000;
			PWMLER=(1<<1);
		}
		else if(!(IO0PIN & (1<<2)))
		{
			PWMMR1=30000;
			PWMLER=(1<<1);
		}
		else if(!(IO0PIN & (1<<3)))
		{
			PWMMR1=45000;
			PWMLER=(1<<1);
		}
		else if(!(IO0PIN & (1<<4)))
		{
			PWMMR1=60000;
			PWMLER=(1<<1);
		}
		else
		{
			PWMMR1=0;
			PWMLER=0x2;
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
	  PINSEL0=0x00000002;
	  PWMMR0=60000;
	  PWMTCR=0x09;
	  PWMMCR=0x02;
	  PWMPR=0;
	  PWMPCR=(1<<9);
}
