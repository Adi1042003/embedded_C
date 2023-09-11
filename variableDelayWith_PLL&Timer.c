#include <lpc214x.h>

void PLL(void) {
  PLL0CON = 0x01;
	PLL0CFG = 0x24;
	PLL0FEED =  0xAA;
	PLL0FEED = 0x55;
	while((PLL0STAT & (1<<10))==0);
	PLL0CON = 0x03;
	PLL0FEED =  0xAA;
	PLL0FEED = 0x55;
	VPBDIV = 0x01;
}

void timer(unsigned int T_delay, unsigned int unit) {
  T0CTCR = 0x00; // Timer mode
  T0PR = (unit)-1; // 1 second delay at 60 MHz clock
  T0TCR = 0x02; // Reset
  T0TCR = 0x01; // Enable
  T0MR0 = T_delay;
  while (T0TC != T0MR0);
  T0TCR = 0x00;
  T0TC = 0;
}

int main() {
  PINSEL0 = 0x1F;
  IO0DIR = 0x7;
  PLL();
  while (1) {
    IO0CLR = (1<<2);
    IO0SET = (1<<0);
    timer(5, 60e5); // Function call for 0.5 second delay
	IO0CLR = (1<<0);
    IO0SET = (1<<1);
    timer(5, 60e5); // Function call for 1 millisecond delay
	IO0CLR = (1<<1);
    IO0SET = (1<<2);
    timer(1, 60e6); // Function call for 1 second delay

  }
}
