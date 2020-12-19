#ifndef __NUT_GBA_KERNEL__
#define __NUT_GBA_KERNEL__

#include <nut/types.h>

#include <nut/gba/pixel.h>
#include <nut/gba/scene.h>


void PlotPixel(Pixel p) {
	*(unsigned*)0x04000000 = 0x0403;
	((unsigned short*)0x06000000)[p.x + p.y * 240] = p.color;
}

void PlotScene(Scene s) {
	for (int i = 0; i < 160; i++) {
		for (int j = 0; j < 240; j++) {
			PlotPixel(s.data[i][j]);
		}
	}

	return;
}

#endif //nut Gameboy Advance kernel