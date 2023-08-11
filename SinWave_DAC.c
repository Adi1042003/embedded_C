//sin wave generation using DAC


#include <lpc214x.h>
#include "math.h"
#define pi 3.142

int delay(unsigned int time) {
    int x, y;
    for(x = 0; x <= time; x++)
        for(y = 0; y <= 1275; y++);
    return 0;
}

int main(void) {
    int i;
    volatile double X;
	int dacValue;
    PINSEL1 = (1 << 19);
    IO0DIR = (1 << 25);
    
    while(1) {
        for(i = 0; i <= 1024; i++) 
		{
            X = sin(i * 2 * pi / 1024); 
            dacValue = (int)((X + 1.0) * 512); 
            DACR = (dacValue << 6);
        }
    }
    return 0;
}
