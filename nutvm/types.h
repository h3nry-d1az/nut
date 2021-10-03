#ifndef __NUTVM_TYPES_H__
#define __NUTVM_TYPES_H__

#include <nut/types.h>

#include "settings.h"
#include "opcodes.h"
#include "registers.h"
#include "flags.h"


typedef u8 byte_t;

typedef byte_t                 memory_t[MEMSIZE * 1024];
typedef enum   __OPCODE_T__    opcode_t;
typedef struct __REGISTERS_T__ registers_t;
typedef enum   __FLAG_T__      flag_t;


#endif // !__NUTVM_TYPES_H__