#ifndef __NUTVM_REGISTERS_H__
#define __NUTVM_REGISTERS_H__

#include <nut/types.h>

// Registers enum
enum __REGISTERS_ENUM__ {
    R_R0 = 0x00,
    R_R1 = 0x01,
    R_R2 = 0x02,
    R_R3 = 0x03,
    R_R4 = 0x04,
    R_R5 = 0x05,
    R_R6 = 0x06,
    R_R7 = 0x07,
    R_R8 = 0x08,
    R_R9 = 0x09,
    R_AX = 0x0A,
    R_BX = 0x0B,
    R_CX = 0x0C,
    R_DX = 0x0D,
    R_EX = 0x0E,
    R_FX = 0x0F,

    R_PC   = 0x10,
    R_COND = 0x11,

    R_COUNT = 18
}

// Registers struct
struct __REGISTERS_T__ {
    u16 R0;
    u16 R1;
    u16 R2;
    u16 R3;
    u16 R4;
    u16 R5;
    u16 R6;
    u16 R7;
    u16 R8;
    u16 R9;
    u16 AX;
    u16 BX;
    u16 CX;
    u16 DX;
    u16 EX;
    u16 FX;

    u16 PC;
    boolean COND;
}


#endif // !__NUTVM_REGISTERS_H__