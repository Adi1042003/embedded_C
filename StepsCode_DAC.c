//steps code for dac

#include <lpc214x.h>

int delay (unsigned int time)
{
	int x,y;
	for(x=0;x<=time;x++)
	for(y=0;y<=1275;y++);
	return 0;
}

int main(void)
{
PINSEL1=(1<<19);
IO0DIR=(1<<25);
while(1)
{
	DACR=(0<<6);
	delay(1);
	DACR=(255<<6);
	delay(1);
	DACR=(511<<6);
	delay(1);
	DACR=(767<<6);
	delay(1);
	DACR=(1023<<6);
	delay(1);
}
}
