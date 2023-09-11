/* Write an embedded C program to read a character from the keyboard using an interrupt mechanicsm and baud rate to be 4800 given PCLK=16MHz. */

#include<lpc214x.h>
#include<stdint.h>

char rx;
void UART0_init(void);

int main(void);

__irq void UART0_Interrupt(void)
{
    int iir_value;
    iir_value = U0IIR;
    if (iir_value & (1<<4))
    {
        rx = U0RBR;
    }
    U0THR = rx;
    while ((U0LSR & (1<<5)) == 0);
    VICVectAddr = 0x00;
}

void UART0_init(void)
{
    PINSEL0 |= 0x05;
    U0LCR = 0x83; 
    U0DLM = 0x00;  // For baud rate of 4800 with Pclk = 16MHz
    U0DLL = 0xD0;  
    U0LCR = 0x03; 
    // Enable UART0 interrupts (THRE and RBR)
    U0IER = 0x03;
}

int main(void)
{
    UART0_init();
    VICVectAddr0 = (unsigned)UART0_Interrupt;
    VICVectCntl0 = (1<<5)|6;
    VICIntEnable = (1<<6);
    VICIntSelect = 0x0;
    while (1);
}
