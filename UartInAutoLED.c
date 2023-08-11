/*3. Write an embedded c Program to read the key pressed from the keyboard Such that, if  A is pressed LED connected at P1.16 to be ON , 
 B is pressed P1.17 to be ON and if any other key is pressed then buzzer at PO.18 to be ON.*/


#include <lpc214x.h>
#include <string.h>

void PLL_init(void);

int main()
{
    unsigned char msg= 0;
    PLL_init();
    PINSEL0 = 0x05;
    PINSEL2 = 0x00; // Set P1.16, P1.17, and P1.18 as GPIO
    IODIR1 = (1 << 16) | (1 << 17) | (1 << 18); // Set P1.16, P1.17, and P1.18 as output
    IO1CLR = (1 << 16) | (1 << 17) | (1 << 18); // Clear P1.16, P1.17, and P1.18 initially
    U0LCR = 0x83;
	U0DLL = 0x87;
    U0DLM = 0x01;
    U0LCR = 0x03;

    while (1) {
        while (!(U0LSR & (1 << 0)));
        msg = U0RBR;
        if (msg == 'A') 
		{
            IO1SET = (1 << 16); // LED for 'A'
            IO1CLR = (1 << 17) | (1 << 18); // Turn off LED for 'B' and led
        } 
		else if (msg == 'B') 
		{
            IO1SET = (1 << 17); // LED for 'B'
            IO1CLR = (1 << 16) | (1 << 18); // Turn off LED for 'A' and buzzer
        } 
		else 
		{
            IO1SET = (1 << 18); // Buzzer for other characters
            IO1CLR = (1 << 16) | (1 << 17); // Turn off LEDs
        }
    }
}

void PLL_init(void)
{
    PLL0CON = 0x01;
    PLL0CFG = 0x24;
    PLL0FEED = 0xAA;
    PLL0FEED = 0x55;
    while (!(PLL0STAT & (1 << 10)));
    PLL0CON = 0x03;
    PLL0FEED = 0xAA;
    PLL0FEED = 0x55;
    VPBDIV = 0x01;
}
