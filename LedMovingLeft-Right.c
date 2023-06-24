#include <LPC214x.h>  
int i;
int delay (unsigned int time)
{
	int x,y;
	for(x=0;x<=time;x++)
	for(y=0;y<=1275;y++);//generate 1 microsec ka delay
	return 0;
}	  
int main() {
  PINSEL0 = 0x00FF;//select P0.0 - P0.15
  IO0DIR |= 0xFF;  
	for(i=7;i>=0;i--)
	{
		IO0CLR|=0XFF00;
		IO0SET|=(1<<i);//moving from left to right 
		delay(2000);
		IO0CLR|=(1<<i);//clear the last instance of the led 
	}		
}
