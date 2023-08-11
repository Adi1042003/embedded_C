/*4.  Write an embedded c Program to read the key pressed from the keyboard Such that, if  A is pressed  then generate  a 50% duty cycle wave ,
  if  B is pressed then generate a 60 % duty cycle wave using PWM. */


#include <lpc214x.h>

void PLL_init(void);
void PWM_init(void);

int main()
{
    unsigned char msg=0;
	PLL_init();
	PWM_init();
    PINSEL0 = 0x05 | (1<<15); //again init pensel as it clear pwm pin as pwm else use PWM5
    U0LCR = 0x83;
    U0DLM = 0x01;
    U0DLL = 0x87;
    U0LCR = 0x03;

    while (1) {

        while (!(U0LSR & (1 << 0)));
        msg = U0RBR;
		while (!(U0LSR & (1 << 5)));
        U0THR = msg;
		
        if (msg == 'A') 
		{
        	PWMMR2=7500;//50% duty cycle
			PWMLER=(1<<2);
        } 
		else if (msg == 'B') 
		{
			PWMMR2=9000;//60% duty cycle
            PWMLER=(1<<2);
        }
		else
		{
			PWMMR2=2000;//0% duty cycle
            PWMLER=(1<<2);
		} 
    }
}

void PLL_init(void)
{
    PLL0CON = 0x01;
    PLL0CFG = 0x24;
    PLL0FEED = 0xAA;
    PLL0FEED = 0x55;
    while (!(PLL0STAT & (1 << 10)));
    PLL0CON = 0x03;
    PLL0FEED = 0xAA;
    PLL0FEED = 0x55;
    VPBDIV = 0x01;
}
void PWM_init()
{
	  PINSEL0=(1<<15);
	  PWMMR0=15000;
	  PWMTCR=0x09;
	  PWMMCR=0x02;
	  PWMPR=0;
	  PWMPCR=(1<<10);
}
