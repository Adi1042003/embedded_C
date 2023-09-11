#include<lpc214x.h>
int i,j;
void delay(int time)
{
	for(i=0;i<time;i++)
	for(j=0;j<120;j++);
}
__irq void Ext_ISR(void)
{
	long temp;
	temp = EXTINT;
	IO0PIN=~IO0PIN;
	delay(10);
	EXTINT = temp;
	VICVectAddr= 0x00;
}
void init_ext(void)
{
	PINSEL0 |= (0x00<<16)|(0x03<<2);
	IO0DIR = (0xFF<<16);
	EXTMODE=0x01;
	EXTPOLAR=0x00;
	VICVectAddr0=(unsigned int) Ext_ISR;
	VICVectCntl0=(1<<5)|14;
	VICIntSelect=0x0;
	VICIntEnable =(1<<14);
}
int main()
{
  init_ext();
  while(1)
  {
  }
}
