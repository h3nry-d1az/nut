#ifndef __NUT_SOUND_MM__
#define __NUT_SOUND_MM__

#include <nut/types.h>

function PlaySound(u32 nFrequence) {
	u32 Div;
	u8  tmp;

	Div = 1193180 / nFrequence;
	outb(0x43, 0xb6);
	outb(0x42, (uint8_t) (Div) );
	outb(0x42, (uint8_t) (Div >> 8));

	tmp = inb(0x61);

	if (tmp != (tmp | 3)) {
		outb(0x61, tmp | 3);
	}
}

function NoSound() {
	u8 tmp = inb(0x61) & 0xFC;
	outb(0x61, tmp);
}

#endif //nut sound module