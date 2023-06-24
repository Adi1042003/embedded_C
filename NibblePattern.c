#include <LPC214x.h>  
int delay (unsigned int time)
{
	int x,y;
	for(x=0;x<=time;x++)
	for(y=0;y<=1275;y++);
	return 0;
}	  
int main() {
  PINSEL0 = 0xFFFF;
  IO0DIR |= 0xFF;  
  IO0SET|=0xCC;
  delay(1000);
  IO0CLR|=0xCC;
  delay(1000);		
}
