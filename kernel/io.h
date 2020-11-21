#ifndef NUT_IO_H
#define NUT_IO_H

u8 inb(u16 port) {
	u8 ret;
	asm volatile("inb %1, %0" : "=a"(ret) : "d"(port));
	return ret;
}

function outb(u16 port, u8 data) {
	asm volatile("outb %0, %1" : "=a"(data) : "d"(port));
}

char charin() {
	char character = 0;
	while ((character = inb(KEYBOARD_PORT)) != 0) {
		if (character > 0)
			return character;
	}

	return character;
}

String strin() {
	while (charin() != ' ') {
		commands[command_num][command_char_num] = __kernel_input();
		command_char_num++;

	} if (__kernel_input() == ' ') {
		command_char_num = 0;
		command_num++;

		return commands[command_num + 1];
	}
}
//input

function newline() {
	if (next_line >= 55) {
		next_line = 0;
		clear_vga_buffer(&vga_buffer, __def_fore_color, __def_back_color);
	}

	vga_index = 80 * next_line;
	next_line++;
}

function charout(char character, u8 fore_color, u8 back_color) {
	vga_buffer[vga_index] = vga_entry(character, fore_color, back_color);
	vga_index++;
}

function strout(String str, u8 fore_color, u8 back_color) {
	u32 index = 0;

	while (str[index]) {
		charout(str[index], fore_color, back_color);
		index++;
	}
}

function intout(int num, u8 fore_color, u8 back_color) {
	char str_num[digits(num) + 1];
	ItoA(num, str_num);
	strout(str_num, fore_color, back_color);
}

function gotoxy(u16 x, u16 y) {
	vga_index = 80 * y;
	vga_index += x;
}

void clear_screen(u8 fore_color, u8 back_color) {
	clear_vga_buffer(&vga_buffer, fore_color, back_color);
}
//output

void sleep(u32 timer_count) {
	while (1) {
		asm volatile("nop");
		timer_count--;
		if (timer_count <= 0)
			break;
	}
}

#endif //nut I/O module