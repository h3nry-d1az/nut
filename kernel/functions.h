#ifndef NUT_FUNCTIONS_H
#define NUT_FUNCTIONS_H

u16 vga_entry(unsigned char ch, u8 fore_color, u8 back_color);
function clear_vga_buffer(u16** buffer, u8 fore_color, u8 back_color);
function init_vga(u8 fore_color, u8 back_color);
//VGA functions

u32 strlen(const String str);
u32 digits(int num);
function ItoA(int num, String number);
//util functions

u8 inb(u16 port);
function outb(u16 port, u8 data);
char charin();
String strin();
function newline();
function charout(char character, u8 fore_color, u8 back_color);
function strout(String str, u8 fore_color, u8 back_color);
function centered_strout(String str, u8 fore_color, u8 back_color);
function intout(int num, u8 fore_color, u8 back_color);
function gotox(u16 x);
function gotoy(u16 y);
function gotoxy(u16 x, u16 y);
function clear_screen(u8 fore_color, u8 back_color);
//I/O functions

u16 GetBoxDrawChar(u8 chn, u8 fore_color, u8 back_color);
function DrawSimpleBox(u16 x, u16 y,
    u16 width, u16 height,
    u8 fore_color, u8 back_color,
    u8 topleft_ch,
    u8 topbottom_ch,
    u8 topright_ch,
    u8 leftrightside_ch,
    u8 bottomleft_ch,
    u8 bottomright_ch);
function DrawBox(u8 boxtype,
    u16 x, u16 y,
    u16 width, u16 height,
    u8 fore_color, u8 back_color);
function FillBox(u8 ch,
    u16 x, u16 y,
    u16 width, u16 height,
    u8 color);
//UI functions

#endif //nut function prototypes