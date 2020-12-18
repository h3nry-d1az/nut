#ifndef __NUT_FUNCTIONS_H__
#define __NUT_FUNCTIONS_H__

function halt();
function panic(String msg);
//abort functions

function Log(String msg, u8 fore_color, u8 back_color);
//log functions

u16 switch_endian16(u16 nb);
u32 switch_endian32(u32 nb);
//network functions

#endif //nut function prototypes