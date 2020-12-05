#ifndef __NUT_IMAGE_H__
#define __NUT_IMAGE_H__

typedef u8 VGA_Map[HEIGHT][WIDTH];


function DrawMap(VGA_Map map) {
	for (int i = 0; i < VGA_HEIGHT; i++) {
		for (int j = 0; j < VGA_WIDTH; j++) {
			charout(' ', BLACK, (color)map[i][j]);
		}
	}
}
//Draw VGA map

#endif //nut image render module
