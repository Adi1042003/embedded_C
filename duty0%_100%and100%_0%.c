//6. write a code for increasing and decreasing the pwm duty cycle 0% to 100% and then 100% to 0% 


int i;

#include"lpc214x.h"

void PLL_init(void);
void PWM_init(void);

int main()
{
	PLL_init();
	PWM_init();
	while(1)
	{
	    for(i=0;i<=6000;i++)
		{
			PWMMR5 = i;
			PWMLER = (1<<5);
		}
		for(i=6000;i>=0;i--)
		{
			PWMMR5 = i;
			PWMLER = (1<<5);
		}

	}
}

void PLL_init(void)
{
	PLL0CON = 0x01;
	PLL0CFG = 0x24;
	PLL0FEED = 0xAA;
	PLL0FEED = 0x55;
	while((PLL0STAT & (1<<10))==0);
	PLL0CON = 0x03;
	PLL0FEED = 0xAA;
	PLL0FEED = 0x55;
	VPBDIV = 0x01;
}
void PWM_init(void)
{
	PINSEL1 = (1<<10);
	PWMMR0 = 6000;
	PWMPR = 0;
	PWMTCR = 0x09;
	PWMMCR = 0x02;
	PWMPCR = (1<<13);
}

