/*
 * Ytochka.c
 *
 * Created: 29.04.2015 17:58:45
 *  Author: ADmin
 */ 

#define F_CPU 8000000UL
#define clrscr {PORTB=~0x00; PORTD=~0xFF;}

#include <avr/io.h>
#include <avr/delay.h>
#define wait _delay_us(100);
unsigned short mas[60] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xBF,0xC6,0xCC,0xBF,0x3F,0x00,0x1F,0x3F,0x34,0x3F,0x1F,0x00,0x00,0x3B,0x0B,0x3F,0x3F,0x00,0x30,0x30,0x3F,0x3F,0x30,0x30,0x00,0x3F,0x3F,0x33,0x33,0x3F,0x3F,0x00,0x38,0x38,0x08,0x3F,0x3F,0x00,0x3F,0x3F,0x04,0x1A,0x33,0x00,0x1F,0x3F,0x34,0x3F,0x1F,0x00,0x00};
void text();
void ytochka(int);
int main(void)
{  
	DDRB=0xFF;
	DDRD=0xFF;
	clrscr;
	for(;;)
	{
	text();
	
	for(short i  = 0;i<10;i++)
	{_delay_ms(100); ytochka(100); clrscr;}
	clrscr;
	}	

}
void ytochka(int num)
{
	for(int x=0;x<num;x++)
	{   PORTB=~0b10000000;
		PORTD=0b01010100;
		wait;
		PORTB=~0b01000000;
		PORTD=0b00100110;
		wait;
		PORTB=~0b00100000;
		PORTD=0b11110111;
		wait;
		PORTB=~0b00010000;
		PORTD=0b11011111;
		wait;
		PORTB=~0b00001000;
		PORTD=0b10011111;
		wait;
		PORTB=~0b00000100;
		PORTD=0b11110111;
		wait;
		PORTB=~0b00000010;
		PORTD=0b00000111;
		wait;
		PORTB=~0b00000001;
		PORTD=0b00001100;
		wait;
	  }		
		
	
	
}
void text()
{short m = 15;
	
	for(short i= 0;i<52;i++)
	{   if(i==51) m=50;
		for(int k = 0;k<m;k++)
	{
		for(short j = 0;j<8;j++)
		 {PORTB= ~(0b00000001<<j);
			PORTD=mas[i+j];
			wait;
					
		}
	}		
	}
	
}