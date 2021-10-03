#ifndef __NUTVM_OPCODES_H__
#define __NUTVM_OPCODES_H__

typedef enum __OPCODE_T__ {
    OP_BRANCH = 0x00,  /* branch */

    OP_ADD = 0x01,     /* add */
    OP_SUB = 0x02,     /* substract */
    OP_MUL = 0x03,     /* multiply */
    OP_DIV = 0x04,     /* divide */

    OP_LOAD = 0x05,    /* load */
    OP_LOADR = 0x06,   /* load register */
    OP_LOADI = 0x07,   /* load indirect */
    OP_LOADEA = 0x08,  /* load effective address */

    OP_STORE = 0x09,   /* store */
    OP_STORER = 0x0A,  /* store register */
    OP_STOREI = 0x0B,  /* store indirect */

    OP_JUMP = 0x0C,    /* jump */
    OP_JUMPR = 0x0D,   /* jump register */

    OP_AND = 0x0E,     /* bitwise and */
    OP_OR = 0x0F,      /* bitwise or */
    OP_XOR = 0x10,     /* bitwise xor */
    OP_NOT = 0x11,     /* bitwise not */

    OP_RTI = 0x12,     /* unused */
    OP_RES = 0x13,     /* reserved (unused) */
    OP_TRAP = 0x14,    /* execute trap */
    OP_NOP = 0x15      /* no operation */
} opcode_t;


#endif // !__NUTVM_OPCODES_H__