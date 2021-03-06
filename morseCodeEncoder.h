/*morseCodeDecoder.h */

#ifndef MORSECODEENCODER_H
#define MORSECODEENCODER_H

static uint8_t morseCodeLUT[37][11] = {
	{'a', 0xd1, 0xda, 0xaa}, 					//a
	{'b', 0xda, 0xd1, 0xd1, 0xd1, 0xaa}, 		//b
	{'c', 0xda, 0xd1, 0xda, 0xd1, 0xaa}, 		//c
	{'d', 0xda, 0xd1, 0xd1, 0xaa}, 				//d
	{'e', 0xd1, 0xaa}, 							//e
	{'f', 0xd1, 0xd1, 0xda, 0xd1, 0xaa}, 		//f
	{'g', 0xda, 0xda, 0xd1, 0xaa}, 				//g
	{'h', 0xd1, 0xd1, 0xd1, 0xd1, 0xaa}, 		//h
	{'i', 0xd1, 0xd1, 0xaa}, 					//i
	{'j', 0xd1, 0xda, 0xda, 0xda, 0xaa}, 		//j
	{'k', 0xda, 0xd1, 0xda, 0xaa}, 				//k
	{'l', 0xd1, 0xda, 0xd1, 0xd1, 0xaa}, 		//l
	{'m', 0xda, 0xda, 0xaa}, 					//m
	{'n', 0xda, 0xd1, 0xaa}, 					//n
	{'o', 0xda, 0xda, 0xda, 0xaa}, 				//o
	{'p', 0xd1, 0xda, 0xda, 0xd1, 0xaa}, 		//p
	{'q', 0xda, 0xda, 0xd1, 0xda, 0xaa}, 		//q
	{'r', 0xd1, 0xda, 0xd1, 0xaa}, 				//r
	{'s', 0xd1, 0xd1, 0xd1, 0xaa}, 				//s
	{'t', 0xda, 0xaa}, 							//t
	{'u', 0xd1, 0xd1, 0xda, 0xaa}, 				//u
	{'v', 0xd1, 0xd1, 0xd1, 0xda, 0xaa}, 		//v
	{'w', 0xd1, 0xda, 0xda, 0xaa}, 				//w
	{'x', 0xda, 0xd1, 0xd1, 0xda, 0xaa}, 		//x
	{'y', 0xda, 0xd1, 0xda, 0xda, 0xaa}, 		//y
	{'z', 0xda, 0xda, 0xd1, 0xd1, 0xaa}, 		//z
	{'1', 0xd1, 0xda, 0xda, 0xda, 0xda, 0xaa}, //1
	{'2', 0xd1, 0xd1, 0xda, 0xda, 0xda, 0xaa}, //2
	{'3', 0xd1, 0xd1, 0xd1, 0xda, 0xda, 0xaa}, //3
	{'4', 0xd1, 0xd1, 0xd1, 0xd1, 0xda, 0xaa}, //4
	{'5', 0xd1, 0xd1, 0xd1, 0xd1, 0xd1, 0xaa}, //5
	{'6', 0xda, 0xd1, 0xd1, 0xd1, 0xd1, 0xaa}, //6
	{'7', 0xda, 0xda, 0xd1, 0xd1, 0xd1, 0xaa}, //7
	{'8', 0xda, 0xda, 0xda, 0xd1, 0xd1, 0xaa}, //8
	{'9', 0xda, 0xda, 0xda, 0xda, 0xd1, 0xaa}, //9
	{'0', 0xda, 0xda, 0xda, 0xda, 0xda, 0xaa}, //0
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