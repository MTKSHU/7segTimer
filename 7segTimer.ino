/* 
Quad 7seg "clock"
Written for MSP430G2231 (but will work on about anything)
via Energia
Idea & bits from http://www.lucidtronix.com/tutorials/40
4/15/2015 
*/

// specify required pins
int data = P1_0;
int clock = P1_1;
int latch = P1_2;

/*
General info regarding the pinout/etc

Binary Val: 128  64  32  16   8   4   2  +1
595 Pins:   QH   QG  QF  QE   QD  QC  QB  QA
Segments:   B    C   A   F    G   D   E   N/C

How display segments correlate with A/B/C etc:
   
------- <-A
|     |
| F   | B
|     |
------- <-G
|     |
| E   | C
|     |
------- <-D

Digits: binary (hex) (dec (eventually))
	0 = 0b11110110 (0xF6)
	1 = 0b11000000 (0xF0)
	2 = 0b10101110 (0xAE)
	3 = 0b11101100 (0xEC)
	4 = 0b11011000 (0xD8)
	5 = 0b01111100 (0x7C)
	6 = 0b01011110 (0x5E)	
	7 = 0b11100000 (0xE0)
	8 = 0b11111110 (0xFE)
	9 = 0b11111000 (0xF8)
	A = 0b11111010 (0xFA)
   *b = 0b01011110 (0x5E)
	c = 0b00001110 (0x0E)
	d = 0b11001110 (0xCE)
	E = 0b00111110 (0x3E)
	F = 0b00111010 (0x3A)
	*= same as 6, 6 needs a hat?
	   6 w/ hat is 0b01111110
	+= 1/QA is useused. Leave low.
*/

// make an array so it's not a pain to work with	
byte digits[] = {
	// 0 to 9
	0b11110110,
	0b11000000,
	0b10101110,
	0b11101100,
	0b11011000,
	0b01111100,
	0b01011110,
	0b11100000,
	0b11111110,
	0b11111000
};


void setup() {
	// set output to control the shift register
	pinMode(data, OUTPUT);
	pinMode(clock, OUTPUT);
	pinMode(latch, OUTPUT);
}

void loop() {
	// update minutes, tenminutes, hours, tenhours, cascading
	for (int minutes = 0; minutes < 10; minutes++) {
		for (int tenminutes = 0; tenminutes < 61; tenminutes++) {
			for (int hours = 0; hours < 5; hours++) {
				for (int tenhours = 0; hours < 3; hours++) {
				
					//latch low to freeze 595
					digitalWrite(latch, LOW);
					
					// write data to registers
					// this assumes that the 1-minute register is first.
					// If not, reverse these shiftOuts.
					// LSBFIRST mandates that the bits are written lo->hi
					shiftOut(data, clock, LSBFIRST, digits[minutes]);
					shiftOut(data, clock, LSBFIRST, digits[tenminutes]);
					shiftOut(data, clock, LSBFIRST, digits[hours]);
					shiftOut(data, clock, LSBFIRST, digits[tenhours]);
					
					// latch high to display values
					digitalWrite(latch, HIGH);
					
					// wait 60 seconds before updating again
					delay(60000);
				}
			}
		}
	}
}