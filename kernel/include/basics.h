#ifndef __NUT_BASIC_UTILS_H__
#define __NUT_BASIC_UTILS_H__

static String* commands;

static u32    command_char_num = 0;
static u32    command_num      = 0;


#define __def_back_color BLACK
#define __def_fore_color WHITE

static u8 actual_back_color = BLACK;
static u8 actual_fore_color = WHITE;

function set_color(u8 fore, u8 back) {
    actual_fore_color = fore;
    actual_back_color = back;
}

#endif //nut basic utils module