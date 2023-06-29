#include <LPC214x.h>  
int i;
unsigned int pattern[]={0xAAAAAAA,0x5555555};
int delay (unsigned int time)
{
	int x,y;
	for(x=0;x<=time;x++)
	for(y=0;y<=1275;y++);//generate 1 microsec ka delay
	return 0;
}	  
int main() {
  PINSEL0 = 0x00000000;//select P0.0 - P0.15 
  PINSEL1 = 0x00000000;
  IO0DIR |=0xFFFFFFF;  
  while(1){
  	for(i=0;i<=1;i++)
	{
		delay(100);
		IO0SET |=pattern[i];
		delay(1000);
		IO0CLR |=pattern[i];
 
	}
	}	
}
