#ifndef __NUTVM_TYPES_H__
#define __NUTVM_TYPES_H__

#include <nut/types.h>

#include "settings.h"
#include "registers.h"


typedef u8 byte_t;

typedef byte_t[MEMSIZE*1024] memory_t;
typedef struct __REGISTERS__ registers_t;


#endif // !__NUTVM_TYPES_H__