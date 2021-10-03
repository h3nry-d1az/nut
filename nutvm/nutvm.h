#ifndef __NUTVM_MACHINE_H__
#define __NUTVM_MACHINE_H__

#include "types.h"
#include "settings.h"


typedef struct __NUTVM_T__ {
	memory_t    memory;
	registers_t registers;

	byte_t* program;
} nutVM_t;


nutVM_t InitNewVM(byte_t program[]) {
	return (nutVM_t) {
		{},
		(registers_t) {
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
			PCSTART, FALSE
		},

		program
	};
}


#endif // !__NUTVM_MACHINE_H__
