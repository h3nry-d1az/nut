#ifndef __NUT_CURSOR_MM__
#define __NUT_CURSOR_MM__

#include <nut/types.h>

function EnableCursor(u8 cursor_start, u8 cursor_end) {
	outb(0x3D4, 0x0A);
	outb(0x3D5, (inb(0x3D5) & 0xC0) | cursor_start);

	outb(0x3D4, 0x0B);
	outb(0x3D5, (inb(0x3D5) & 0xE0) | cursor_end);
}

function DisableCursor() {
	outb(0x3D4, 0x0A);
	outb(0x3D5, 0x20);
}

#endif //nut cursor module