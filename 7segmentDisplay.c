#include"lpc214x.h"
unsigned int i=0;
void delay(unsigned int time)
{		int k,g;
		 for(k=0;k<=time;k++)
		 for(g=0;g<=1275;g++);
}

unsigned int Disp[16]={ 0x003F0000,//0
0x00060000, // 1
0x005B0000, // 2
0x004F0000, // 3
0x00660000, // 4
0x006D0000, // 5
0x007D0000, // 6
0x00070000, // 7
0x007F0000, // 8
0x006F0000, // 9
0x00770000, // A
0x007C0000, // b
0x00390000, // C
0x005E0000, // d
0x00790000, // E
0x00710000 }; // F

#define SELDISP1 0x10000000
#define SELDISP2 0x20000000
#define SELDISP3 0x40000000
#define SELDISP4 0x80000000
#define ALLDISP  0xF0000000
#define DATAPORT 0x00FF0000

int main()
{
    PINSEL1 = 0X00000000;
	IO0DIR = 0xF0FF0000;
	IO1DIR = 0x00000000;
	while(1)
          {															
				IO0SET = ALLDISP;
				IO0CLR = 0x00FF0000;
				IO0SET = Disp[i];
				if(!(IO1PIN & 0x00800000))
				{
				delay(2000);
				i++;
				if(i== 16)
				{
					i=0;
					IO0CLR = 0XF0FF0000;
				}
				}
			}
}
