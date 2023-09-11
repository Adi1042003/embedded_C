#include <LPC214x.h>  
int i;
int delay (unsigned int time)
{
	int x,y;
	for(x=0;x<=time;x++)
	for(y=0;y<=1275;y++);//generate 1 microsec ka delay
	return 0;
}	  
unsigned int Display[]= {
0x3F00,
0x0600,
0x5B00,
0x4F00,
0x6600,
0x6D00,
0x7D00,
0x0700,
0x7F00,
0x6F00
};
int main() {
  PINSEL0 = 0x00000000;//select P0.0 - P0.15
  PINSEL2 = 0x00000000; 
  IO0DIR |=(0xFF<<8);
  IO1DIR |=(1<<9);
   
  while(1){
  	for(i=0;i<=9;i++)
	{
		delay(100);
		IO0SET |=Display[i];
		delay(1000);
		IO0CLR |=Display[i];
		if(i==9)
		{
			IO1SET |=(1<<9);//buzzer
			delay(1000);
			IO1CLR |=(1<<9);
		}
	}
	}	
}
