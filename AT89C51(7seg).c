#include <reg51.h>

#define segment_data P1
int i,j;
// Array to store segment data for each digit (0-9) and character (A-F)
unsigned char digitData[16] = {
     0x3F,//0
0x06, // 1
0x5B, // 2
0x4F, // 3
0x66, // 4
0x6D, // 5
0x7D, // 6
0x07, // 7
0x7F, // 8
0x6F, // 9
0x77, // A
0x7C, // b
0x39, // C
0x5E, // d
0x79, // E
0x71 }; // F


// Function to display a digit or character on the 7-segment display
void displayDigit(unsigned char value) {
    if (value < 16) {
        segment_data = digitData[value];
    } else {
        segment_data = 0xFF; // Turn off all segments
    }
}

// Function for delay loop
void delayLoop(unsigned int time) {
    for (i = 0; i < time; i++) {
        for (j = 0; j < 1275; j++) {
            // Delay loop
        }
    }
}

// Start of main program
void main() {
    unsigned char counter = 0;
    
    while (1) {
        displayDigit(counter);
        counter++;
        
        if (counter == 16) {
            counter = 0;
        }
        
        delayLoop(100); // Delay for approximately 1 second
    }
}
