#ifndef __NUT_KERNEL__
#define __NUT_KERNEL__

#define NUT_VERSION "v0.1.2"


#define VGA_ADDRESS 0xB8000
#define BUFSIZE     2200

#define TRUE        1
#define FALSE       0

#define NULL        0
//consts

#include "types.h"
#include "functions.h"

static String* commands;

static u32    command_char_num = 0;
static u32    command_num = 0;

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


#include "vga.h"
#define __def_back_color BLACK
#define __def_fore_color WHITE

static u8 actual_back_color = BLACK;
static u8 actual_fore_color = WHITE;

function set_color(u8 fore, u8 back) {
    actual_fore_color = fore;
    actual_back_color = back;
}


#include "utils.h"
#include "keys.h"
#include "io.h"
#include "log.h"
#include "abort.h"
#include "ui.h"
//modules

#endif //nut kernel header