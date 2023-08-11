/* 1. Write an embedded C program to read from the keyboard and store in an array and then 
  display it on serial monitor such that baud rate to be 9600 and given PCLK=16MHz. */

#include <lpc214x.h>

void PLL_init(void);


unsigned int i;
int main()
{
    unsigned char msg[]={0};
	PLL_init();
    PINSEL0 = 0x05; 
    U0LCR = 0x83;
    U0DLM = 0x00;
    U0DLL = 0x68; //104 
    U0LCR = 0x03;

    while (1) 
	{
	   for(i=0;msg[i]!='$';i++)
	   {
        	while (!(U0LSR & (1 << 0)));
        	msg[i] = U0RBR; 
			if(msg[i]=='\r'){break;}
	   }
	   for(i=0;msg[i]!='\0';i++)
	   {
			while (!(U0LSR & (1 << 5)));
        	U0THR = msg[i];
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
    VPBDIV = 0x00; //almost 16MHz freq
}
