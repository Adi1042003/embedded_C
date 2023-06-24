#include <LPC214x.h>  
int i;
unsigned int pattern[]={0xCC,0x33};
int delay (unsigned int time)
{
	int x,y;
	for(x=0;x<=time;x++)
	for(y=0;y<=1275;y++);//generate 1 micro sec ka delay
	return 0;
}	  
int main() {
  PINSEL0 = 0x00FF;//select P0.0 - P0.15
  IO0DIR |= 0xFF;  

	for(i=0;i<2;i++)
	{
		IO0CLR|=0xFF00;
		IO0SET|=pattern[i];//array call with index
		delay(2000);//delay function call
		IO0CLR|=pattern[i];
	}		
}
