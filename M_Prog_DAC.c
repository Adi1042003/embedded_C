//M Program using DAC

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
int j;
PINSEL1=(1<<19);
IO0DIR=(1<<25);
while(1)
{	
	DACR=(1024<<6);

	for(j=1024;j>=512;j--)
	{
		DACR=(j<<6);
	}
	for(j=512;j<=1024;j++)
	{
		DACR=(j<<6);
	}
	DACR=(0X00<<6);
	delay(1);
}
}
