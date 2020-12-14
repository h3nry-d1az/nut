#ifndef __NUT_VGA_H__
#define __NUT_VGA_H__

#include <nut/utils.h>

const unsigned VGA_ADDRESS = 0xB8000;
const unsigned BUFSIZE = 2200;

static u16*   vga_buffer;
static u32    vga_index;

static u32    next_line = 1;

int ASCII_NUMBERS[10] = {
    0x30,
    0x31,
    0x32,
    0x33,
    0x34,
    0x35,
    0x36,
    0x37,
    0x38,
    0x39
};

const u8 VGA_WIDTH  = 80;
const u8 VGA_HEIGHT = 24;

#define WIDTH  80
#define HEIGHT 24
//#define alternative

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


#include <nut/colors.h>



#endif //nut vga module