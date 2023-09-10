//buzzer should be on as long as switch is pressed 

#include <Lpc214x.h>

#define Buzz_pin (1<< 9)
#define on_off_pin (1<< 16)

int main(void) {
	PINSEL0|= 0x00000000;
	PINSEL1|= 0x00000000;
    IO0DIR |= Buzz_pin; 
    IO0DIR &= ~on_off_pin;
	
    while (1) {
	  if(!(IO1PIN & on_off_pin))
	  {
                
	 	IO0SET = Buzz_pin;
	  }
      else 
	   {
			IO0CLR = Buzz_pin; 
       }  
    }
}
