#ifndef __NUT_VGA_H__
#define __NUT_VGA_H__

#define VGA_WIDTH  80
#define VGA_HEIGHT 24

enum vga_color {
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    GREY,
    DARK_GREY,
    BRIGHT_BLUE,
    BRIGHT_GREEN,
    BRIGHT_CYAN,
    BRIGHT_RED,
    BRIGHT_MAGENTA,
    YELLOW,
    WHITE,
};
//VGA colors

u16 vga_entry(unsigned char ch, u8 fore_color, u8 back_color) {
    u16 ax = 0;
    u8  ah = 0, al = 0;

    ah = back_color;
    ah <<= 4;
    ah |= fore_color;
    ax = ah;
    ax <<= 8;
    al = ch;
    ax |= al;

    return ax;
}

function clear_vga_buffer(u16** buffer, u8 fore_color, u8 back_color) {
    for (u32 i = 0; i < BUFSIZE; i++) {
        (*buffer)[i] = vga_entry(NULL, fore_color, back_color);
    }
}

function init_vga(u8 fore_color, u8 back_color) {
    vga_buffer = (u16*)VGA_ADDRESS;
    clear_vga_buffer(&vga_buffer, fore_color, back_color);
}
//VGA interface functions

#endif //nut vga module