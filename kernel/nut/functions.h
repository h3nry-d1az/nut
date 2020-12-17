#ifndef __NUT_FUNCTIONS_H__
#define __NUT_FUNCTIONS_H__

function halt();
function panic(String msg);
//abort functions

FAT32_Sector InitFAT32(u32 size, u16 fversion,
	u32 rcluster, u16 info,
	u16 backup, u8 number,
	u32 id);
//files functions

function Log(String msg, u8 fore_color, u8 back_color);
//log functions

u16 switch_endian16(u16 nb);
u32 switch_endian32(u32 nb)
//network functions

#endif //nut function prototypes