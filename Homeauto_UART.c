/* Write a code to create a home automation system that turns on a light connected to P1.16 when "A"  is received from UART , 
 turn on fan connected to P1.17 when "B" is received ,And turns off a light connected to P1.16 when "C"  is received from UART ,
 And turn off fan connected to P1.17 when "D" is received.*/


#include <lpc214x.h>

int main() {
    unsigned volatile char Burette = 0;
    PINSEL0 = 0x05;
    PINSEL2 = 0x000000;
    IO1DIR = 0xFF;
    U0LCR = 0x83;
    U0DLM = 0x01;
    U0DLL = 0x87;
    U0LCR = 0x03;

    while (1) {
        while (!(U0LSR & (1 << 0)));
        Burette = U0RBR;
        while (!(U0LSR & (1 << 5)));
        U0THR = Burette;

        switch (Burette) {
            case 'A':
                IO1SET = 0x010000;
                break;
            case 'B':
                IO1SET = 0x020000;
                break;
            case 'C':
                IO1CLR = 0x010000;
                break;
            case 'D':
                IO1CLR = 0x020000;
                break;
            default:
                // Handle any other cases if needed
                break;
        }
    }
}
