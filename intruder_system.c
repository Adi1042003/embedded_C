/*   intruder system using an LPC2148 microcontroller and a PIR sensor connected to pin 0.17, and 
    I would like to configure the microcontroller to illuminate an LED on pin 0.8 and activate a buzzer on pin 0.9 whenever motion is detected by the 
     PIR sensor and an on/off switch to start or shut down the system */

#include <Lpc214x.h>

#define led_pin (1 << 8)  
#define motion_pin (1 << 17)
#define Buzz_pin (1<< 9)
#define on_off_pin (1<< 0)

int main(void) {
	PINSEL0|= 0x00000000;
	PINSEL1|= 0x00000000;
    IO0DIR |= led_pin | Buzz_pin; 
    IO0DIR &= ~motion_pin;
    IO0DIR &= ~on_off_pin;
	
    while (1) {
	  if(!(IO0PIN & on_off_pin))
	  {
        if (!(IO0PIN & motion_pin)) {         
                IO0SET = led_pin;
			    IO0SET = Buzz_pin;
            }
         else {
            IO0CLR = led_pin;
			IO0CLR = Buzz_pin; 
        }
	  }
    }
}
