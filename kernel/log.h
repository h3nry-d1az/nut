#ifndef __NUT_LOGOUT_H__
#define __NUT_LOGOUT_H__

function Log(String msg, u8 fore_color, u8 back_color) {
	puts("Nut kernel (v0.1.2) says:\n");
	strout(msg, fore_color, back_color);
	return;
}

#endif //nut kernel logout module