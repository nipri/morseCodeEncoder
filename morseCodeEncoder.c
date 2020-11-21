/*
 * morseCodeDecoder.c
 *
 * Created: 8/2/2019 3:21:28 PM
 * Author : nipri
 
 */ 
//F_CPU defined in project properties
#define F_CPU	16000000UL

#define DIT			0xd1
#define DAH			0xda
#define TIMEOUT		1000		// mS to wait

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


#include "morseCodeEncoder.h"

static volatile uint16_t hiTimeCount, loTimeCount;
static volatile uint8_t byte, count;

//uint8_t string[] = {0x48,0x45,0x4c,0x4c,0x4f};
char string[] = "hello there";


ISR (TIMER1_COMPA_vect)
{
	loTimeCount++;
}

ISR (TIMER3_COMPA_vect)
{
	hiTimeCount++;
}

ISR (TIMER0_COMPA_vect)
{
	count++;
	
	if (count >= 61)
	{
		count = 0;
			
		byte = PORTB;
	
		if (byte & 0x80)
		{
		//	clear_bit(PORTB, 5);
			PORTB &= ~(1 << 7);
		}
	
		else
		{
		//	set_bit(PORTB, 5);
			PORTB |= (1 << 7);
		}
	}
}

int main(void)
{
	static uint8_t length, i, j, k, l;
	static bool done;
	
	/* Timer 0 is flashing the LED for now */
	TCCR0A = 0x0;
	TCCR0B = 0x00; //0x05;
	TIMSK0 = 0x02;
	OCR0A = 0xff;

	/* Timer 1 is a 1 mS counter to track the low time of the digital input */
	TCCR1A = 0x00;
	TCCR1B = 0x01; 
	TIMSK1 = 0x02;
	OCR1A = 0x3e80; // Generate an output compare interrupt every 16000 counts (1 mS at 16 MHz)

	/* Timer 3 is a 1 mS counter to track the high time of the digital input */
	TCCR3A = 0x00;
	TCCR3B = 0x01; 
	TIMSK3 = 0x02;
	OCR3A = 0x3e80; // Generate an output compare interrupt every 16000 counts (1 mS at 16 MHz)	
	
	DDRB = 0x81; // Bit 7 drives the on-board LED, bit one will be our keying GPIO
	
	sei();
	
	length = strlen(string);
//	length = 5;

	set_bit(PORTB, 7);
	
    /* Replace with your application code */
    while (1) 
    {	
		
		_delay_ms(2000);
		
		//Find the ith char in the string
		for(i=0; i<length; i++)
		{
			
			done = false;
			
			for (j=0; (j<=36 && !done); j++)
			{
				if(string[i] == morseCodeLUT[j][0])
				{	
								
					k=1;
					done = false;
				
					do
					{
						loTimeCount=0;
						hiTimeCount=0;
					
						if(morseCodeLUT[j][k] == 0xd1)
						{
//							set_bit(PORTB, 7);
							clear_bit(PORTB, 7);
							
							//hiTimeCount=0;
							loTimeCount=0;
							do 
							{
							//} while (hiTimeCount <= 30);
							} while (loTimeCount <= 10);
							
							//clear_bit(PORTB, 7);
							set_bit(PORTB, 7);
						}
					
						else if(morseCodeLUT[j][k] == 0xda)
						{
							//set_bit(PORTB, 7);
							clear_bit(PORTB, 7);

							//hiTimeCount=0;
							loTimeCount=0;
							do
							{
							//} while (hiTimeCount <= 90);
							} while (loTimeCount <= 30);

							//clear_bit(PORTB, 7);
							set_bit(PORTB, 7);
						}
					
						else if(morseCodeLUT[j][k] == 0xaa)
						{
							done = true;
							//clear_bit(PORTB, 7);
							set_bit(PORTB, 7);
						}
	
						//loTimeCount = 0;
						hiTimeCount = 0;
						do
						{
						//} while (loTimeCount <= 30);
						} while (hiTimeCount <= 30);
					
						k++;
					
					} while (!done);
					
					//loTimeCount = 0;
					hiTimeCount = 0;
			
					do
					{
					//} while (loTimeCount <= 90);
					} while (hiTimeCount <= 30);					
				
				}
				
				else if(string[i] == ' ')
				{
					//loTimeCount = 0;
					hiTimeCount = 0;
					do
					{
					//} while (loTimeCount <= 210);
					} while (hiTimeCount <= 70);
					done = true;
				}
				else
				{
				}
			}
		}
	}
}

