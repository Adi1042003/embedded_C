#include <LPC214x.h>  
void clock_wise(void);
void anti_clock_wise(void);
void delay(unsigned int time)
{
   int	x,y;
   for(x=0;x<=time;x++)
   for(y=0;y<=1275;y++);
}
int main()
{
   PINSEL0|=0x000000;
   IO0SET=0x900;
   IO0SET=(1<<8);
   while(1){
   		delay(100);
		clock_wise();
		delay(100);
		anti_clock_wise();
	 }
}
void clock_wise(void)
{	
	IO0SET |=0xFFFFFFFF;
	delay(1000);//delay to stop the rotation 
	IO0SET |=(1<<8)|(1<<11);
	delay(1000);
}
void anti_clock_wise(void)
{
	IO0SET |=0xFFFFFFFF;
	delay(1000);//delay to stop the rotation
	IO0SET |=(1<<8);
	IO0CLR |=(1<<11);
	delay(1000);
}
