#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>


void manchester(int val)
{
    // send 1 (transition from high to low)
    if (val == 1)
    {
        PORTB = 0b00001000;
        _delay_ms(1);
        PORTB = 0b0000000;
        _delay_ms(1);
    }    
    // send 0 (transition from low to high)
    else
    {
        PORTB = 0b00000000;
        _delay_ms(1);
        PORTB = 0b00001000;
        _delay_ms(1);
    }
    return;
}

int main(void)
{
    //Set pin to output
	DDRB = 0b00001000;

    //transmit id
	while (1) {

        // loop through ID and manchester encode
       
        // toggle for 8 bits
        for (int i = 0; i < 8; i++)
        {
            manchester(1);
        } 

        // send 4 0's
        for (int i = 0; i < 4; i++)
        {
            manchester(0);
        }
        // send 8 bit id
        // id: 01010011
        manchester(0);
        manchester(1);
        manchester(0);
        manchester(1);
        manchester(0);
        manchester(0);
        manchester(1);
        manchester(1);

        // wait for a while
        PORTB = 0b0001000;
        _delay_ms(500);

	}
	return 1;
}
	
