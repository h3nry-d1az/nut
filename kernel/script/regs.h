#ifndef __NUT_LISP_REGISTERS_H__
#define __NUT_LISP_REGISTERS_H__

register char r0;
register char r1;
register char r2;
register char r3;
register char r4;
register char r5;
register char r6;
register char r7;
register char r8;
register char r9;
register char r10;
register char r11;
register char r12;
//first 12 registers

register short ra;
register short rb;
register short rc;
register short re;
register short rx;
//special registers


// It's common to use these registers in mov or free instructions
// with a syntax like this:
// (mov $ra 56)

// you need to put the $ symbol before the register name to specify
// that is a register

#endif //nutlisp registers module