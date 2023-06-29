#include <LPC214x.h>

int i;

int delay(unsigned int time)
{
    int x, y;
    for (x = 0; x <= time; x++)
        for (y = 0; y <= 1275; y++); // generate 1 microsec ka delay
    return 0;
}

int main()
{
    PINSEL2 = 0x00000000; // select P0.0 - P0.15
    PINSEL1 = 0x00000000; // set P0 pins as GPIO
    IO1DIR |= 0xFFFF;
    IO0DIR |= 0x0000;

    while (1)
    {
        if (!(IO0PIN & (1 << 18)))
        {
            for (i = 31; i >= 16; i--)
            {
                IO1SET |= (1 << i); // moving from left to right
                delay(1000);
            }
            IO1CLR |= 0xFFFF0000;
        }
    }
}
