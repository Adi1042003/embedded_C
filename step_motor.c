#include<lpc214x.h>

#define PHASEA (0x09<<12)    //magnet 1
#define PHASEB (0x0C<<12)    //magnet 2
#define PHASEC (0x06<<12)    //magnet 3
#define PHASED (0x03<<12)    //magnet 4

#define Forward 0x00010000
#define Reverse 0x00020000

void delay(unsigned int time)
{	int x,y;
	for(x=0;x<=time;x++)
	for(y=0;y<=1275;y++);
}
void Reverse1(void);
void Forward1(void);
unsigned int steps;

int main(void)
{
		IO0DIR = 0X0000F000;
		IO0CLR = 0X0000F000;
	
	while(1)
	{
			for(steps = 0; steps<50; steps++)
			Forward1();
		    for(steps = 0; steps<50; steps++)
			Reverse1();
	}
	
}
void Forward1(void)
{
	      IO0SET = PHASEA;
			delay(1000);
			IO0CLR = PHASEA;
		 
		  IO0SET = PHASEB;
			delay(1000);
			IO0CLR = PHASEB;
		 
		  IO0SET = PHASEC;
			delay(1000);
			IO0CLR = PHASEC;
		 
		  IO0SET = PHASED;
			delay(1000);
			IO0CLR = PHASED;
}
void Reverse1(void)
{
		  IO0SET = PHASED;
			delay(1000);
			IO0CLR = PHASED;
		 
		  IO0SET = PHASEC;
			delay(1000);
			IO0CLR = PHASEC;
		 
		  IO0SET = PHASEB;
			delay(1000);
			IO0CLR = PHASEB;
		 
		  IO0SET = PHASEA;
			delay(1000);
			IO0CLR = PHASEA;
}
