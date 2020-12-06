#ifndef __NUT_IMAGE_H__
#define __NUT_IMAGE_H__

typedef u8 VGAMap[HEIGHT][WIDTH];
typedef u8 Image[][WIDTH];


function DrawMap(VGAMap map) {
	clear_screen(BLACK, BLACK);
	for (int i = 0; i < VGA_HEIGHT; i++) {
		for (int j = 0; j < VGA_WIDTH; j++) {
			gotoxy(j, i);
			charout(' ', BLACK, (color)map[i][j]);
		}
	}
}
//Draw VGA map

function DrawImage(Image im) {
	clear_screen(BLACK, BLACK);
	for (int i = 0; i < (sizeof(im) / sizeof(im[0])); i++) {
		for (int j = 0; j < (sizeof(im[0]) / sizeof(im[0][0])); j++) {
			gotoxy(j, i);
			charout(' ', BLACK, (color)im[i][j]);
		}
	}
}
//Draw image

#endif //nut image render module
