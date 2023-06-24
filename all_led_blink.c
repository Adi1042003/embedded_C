#include <LPC214x.h>  
void delay(unsigned int time)
{
   int	x,y;
   for(x=0;x<=time;x++)
   for(y=0;y<=1275;y++);
}
int main()
{
   while(1){
	 PINSEL0 =0xFFFF;
	 PINSEL1=0xFFFF;
	 IO0DIR=0xFFFFFFFF;
	 IO0SET|=0xFFFFFFFF;
	 delay(1000);
	 IO0CLR|=0xFFFFFFFF;
	 delay(1000);
	 }
}
