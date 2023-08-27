#include <lpc214x.h>

unsigned int init_ADC(void);

int main(void)
{
    PINSEL0 = (1 << 24);
    while (1)
    {
        unsigned int adcValue = init_ADC();
    }
}
unsigned int init_ADC(void)
{
    unsigned int adcdata;
    AD0CR |= (1 << 1) | (13 << 8) | (1 << 21) | (1 << 24) | (1 << 16);
    while ((AD0GDR & (1U << 31)) == 0U);
    adcdata = (AD0GDR >> 6) & 0x3FF;
    return adcdata;
}
