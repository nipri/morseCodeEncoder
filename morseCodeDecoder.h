/*morseCodeDecoder.h */

#ifndef MORSECODEDECODER_H
#define MORSECODEDECODER_H

void HD44780_GotoXY(uint8_t, uint8_t);
void HD44780_Init(void);
void HD44780_ReadBusy(void);
void HD44780_WriteData(uint8_t, uint8_t, char*, uint8_t);
void HD44780_WriteCommand(uint8_t);

static uint8_t intlMorseCodeTable[37][11] = {
	{0xd1, 0xda, 0xaa, 0x41}, 					//a
	{0xda, 0xd1, 0xd1, 0xd1, 0xaa, 0x42}, 		//b
	{0xda, 0xd1, 0xda, 0xd1, 0xaa, 0x43}, 		//c
	{0xda, 0xd1, 0xd1, 0xaa, 0x44}, 			//d
	{0xd1, 0xaa, 0x45}, 						//e
	{0xd1, 0xd1, 0xda, 0xd1, 0xaa, 0x46}, 		//f
	{0xda, 0xda, 0xd1, 0xaa, 0x47}, 			//g
	{0xd1, 0xd1, 0xd1, 0xd1, 0xaa, 0x48}, 		//h
	{0xd1, 0xd1, 0xaa, 0x49}, 					//i
	{0xd1, 0xda, 0xda, 0xda, 0xaa, 0x4a}, 		//j
	{0xda, 0xd1, 0xda, 0xaa, 0x4b}, 			//k
	{0xd1, 0xda, 0xd1, 0xd1, 0xaa, 0x4c}, 		//l
	{0xda, 0xda, 0xaa, 0x4d}, 					//m
	{0xda, 0xd1, 0xaa, 0x4e}, 					//n
	{0xda, 0xda, 0xda, 0xaa, 0x4f}, 			//o
	{0xd1, 0xda, 0xda, 0xd1, 0xaa, 0x50}, 		//p
	{0xda, 0xda, 0xd1, 0xda, 0xaa, 0x51}, 		//q
	{0xd1, 0xda, 0xd1, 0xaa, 0x52}, 			//r
	{0xd1, 0xd1, 0xd1, 0xaa, 0x53}, 			//s
	{0xda, 0xaa, 0x54}, 						//t
	{0xd1, 0xd1, 0xda, 0xaa, 0x55}, 			//u
	{0xd1, 0xd1, 0xd1, 0xda, 0xaa, 0x56}, 		//v
	{0xd1, 0xda, 0xda, 0xaa, 0x57}, 			//w
	{0xda, 0xd1, 0xd1, 0xda, 0xaa, 0x58}, 		//x
	{0xda, 0xd1, 0xda, 0xda, 0xaa, 0x59}, 		//y
	{0xda, 0xda, 0xd1, 0xd1, 0xaa, 0x5a}, 		//z
	{0xd1, 0xda, 0xda, 0xda, 0xda, 0xaa, 0x31}, //1
	{0xd1, 0xd1, 0xda, 0xda, 0xda, 0xaa, 0x32}, //2
	{0xd1, 0xd1, 0xd1, 0xda, 0xda, 0xaa, 0x33}, //3
	{0xd1, 0xd1, 0xd1, 0xd1, 0xda, 0xaa, 0x34}, //4
	{0xd1, 0xd1, 0xd1, 0xd1, 0xd1, 0xaa, 0x35}, //5
	{0xda, 0xd1, 0xd1, 0xd1, 0xd1, 0xaa, 0x36}, //6
	{0xda, 0xda, 0xd1, 0xd1, 0xd1, 0xaa, 0x37}, //7
	{0xda, 0xda, 0xda, 0xd1, 0xd1, 0xaa, 0x38}, //8
	{0xda, 0xda, 0xda, 0xda, 0xd1, 0xaa, 0x39}, //9
	{0xda, 0xda, 0xda, 0xda, 0xda, 0xaa, 0x30}, //0
	{0xd1, 0xd1, 0xd1, 0xda, 0xda, 0xda, 0xd1, 0xd1, 0xd1, 0xaa, 0x3E} //SOS
};


#define set_bit(port, bit)		\
__asm__ __volatile__ (			\
"sbi %0, %1"					\
:  /* no outputs */				\
: "I" (_SFR_IO_ADDR(port)),		\
"I" (bit)						\
)

#define clear_bit(port, bit)	\
__asm__ __volatile__ (			\
"cbi %0, %1"					\
:  /* no outputs */				\
: "I" (_SFR_IO_ADDR(port)),		\
"I" (bit)						\
)

#endif