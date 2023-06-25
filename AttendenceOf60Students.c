#include <lpc214x.h>

unsigned int count = 0;
unsigned int digit, digit1;

unsigned int Disp[10] = {
    0x003F0000, // 0
    0x00060000, // 1
    0x005B0000, // 2
    0x004F0000, // 3
    0x00660000, // 4
    0x006D0000, // 5
    0x007D0000, // 6
    0x00070000, // 7
    0x007F0000, // 8
    0x006F0000  // 9
};

#define SELDISP1 0x10000000
#define SELDISP2 0x20000000
#define ALLDISP  0xF0000000

void delay(unsigned int time) {
    unsigned int i, j;
    for (i = 0; i <= time; i++)
    for (j = 0; j <= 1275; j++); // Delay loop
  
}

int main() {
    PINSEL1 = 0x00000000;
    IO0DIR = 0xF0FF0000; // 1 means output
    IO1DIR = 0x00000000; // 0 means input

    while (1) {
        // P1.23 acts like an input button
        if (!(IO1PIN & (1 << 23))) {
            count++;
            delay(10000);
            digit = count % 10; 
            digit1 = count / 10; 

            IO0SET = SELDISP1;
            IO0CLR = 0x00FF0000;
            IO0SET = Disp[digit]; // Print unit place

            IO0SET |= SELDISP2;
            IO0CLR = 0x00FF0000;
            IO0SET = Disp[digit1]; // Print tens place

            if (count > 60) {
                count = 0;         // Reset count
                IO0CLR = ALLDISP;  // Clear display
            }
        }
    }
}
