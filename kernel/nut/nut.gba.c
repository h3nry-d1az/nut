#ifndef __NUT_GBA_KERNEL__
#define __NUT_GBA_KERNEL__

#include <nut/types.h>
#include <nut/gba/pixel.h>


void plot(Pixel p) {
	*(unsigned*)0x04000000 = 0x0403;
	((unsigned short*)0x06000000)[p.x + p.y * 240] = p.color;
}

#endif //nut Gameboy Advance kernel