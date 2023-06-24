#include <LPC214x.h>  
int j,i;
unsigned int pattern[]={0xDB,0x6D,0xB6};//next instance to display
int delay (unsigned int time)
{
	int x,y;
	for(x=0;x<=time;x++)
	for(y=0;y<=1275;y++);//delay
	return 0;
}	  
int main() {
  PINSEL0 = 0xFF;
  IO0DIR |= 0xFF;  

	for(i=0;i<=2;i++)
	{
		IO0CLR|=0XFF00;
		IO0SET|=pattern[i];//array call with index
		delay(2000);//function call
		IO0CLR|=pattern[i];
	}		
}
