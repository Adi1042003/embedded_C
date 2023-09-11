#include <LPC214x.h>  
int i;
unsigned int pattern[]={0xCC,0x66,0x33,0x99};
int delay (unsigned int time)
{
	int x,y;
	for(x=0;x<=time;x++)
	for(y=0;y<=1275;y++);
	return 0;
}	  
int main() {
  PINSEL0 = 0x00;
  IO0DIR |= 0xFF;  

	for(i=0;i<=3;i++)
	{
		IO0CLR|=0XFF00;
		IO0SET|=pattern[i];
		delay(2000);
		IO0CLR|=pattern[i];
	}		
}
