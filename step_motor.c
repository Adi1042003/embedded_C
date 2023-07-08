#include<lpc214x.h>

#define PHASEA (1<<12)    //magnet 1
#define PHASEB (1<<13)    //magnet 2
#define PHASEC (1<<14)    //magnet 3
#define PHASED (1<<15)    //magnet 4

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
			IO0CLR = 0xFFFFFFFF;
		 
		  IO0SET = PHASEB;
			delay(1000);
			IO0CLR = 0xFFFFFFFF;
		 
		  IO0SET = PHASEC;
			delay(1000);
			IO0CLR = 0xFFFFFFFF;
		 
		  IO0SET = PHASED;
			delay(1000);
			IO0CLR = 0xFFFFFFFF;
	 }
void Reverse1(void)
	 {
		  IO0SET = PHASED;
			delay(1000);
			IO0CLR = 0xFFFFFFFF;
		 
		  IO0SET = PHASEC;
			delay(1000);
			IO0CLR = 0xFFFFFFFF;
		 
		  IO0SET = PHASEB;
			delay(1000);
			IO0CLR = 0xFFFFFFFF;
		 
		  IO0SET = PHASEA;
			delay(1000);
			IO0CLR = 0xFFFFFFFF;
	 }
