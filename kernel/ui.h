#ifndef NUT_UI_H
#define NUT_UI_H

#define BOX_MAX_WIDTH  78
#define BOX_MAX_HEIGHT 23

#define BOX_SINGLELINE 1
#define BOX_DOUBLELINE 2

u16 GetBoxDrawChar(u8 chn, u8 fore_color, u8 back_color) {
    u16 ax = 0;
    u8  ah = 0;

    ah = back_color;
    ah <<= 4;
    ah |= fore_color;
    ax = ah;
    ax <<= 8;
    ax |= chn;

    return ax;
}

void DrawSimpleBox(u16 x, u16 y,
    u16 width, u16 height,
    u8 fore_color, u8 back_color,
    u8 topleft_ch,
    u8 topbottom_ch,
    u8 topright_ch,
    u8 leftrightside_ch,
    u8 bottomleft_ch,
    u8 bottomright_ch)
{
    u32 i;

    vga_index = 80 * y;
    vga_index += x;

    vga_buffer[vga_index] = GetBoxDrawChar(topleft_ch, fore_color, back_color);

    vga_index++;

    for (i = 0; i < width; i++) {
        vga_buffer[vga_index] = GetBoxDrawChar(topbottom_ch, fore_color, back_color);
        vga_index++;
    }

    vga_buffer[vga_index] = GetBoxDrawChar(topright_ch, fore_color, back_color);

    y++;

    vga_index = 80 * y;
    vga_index += x;

    for (i = 0; i < height; i++) {
        vga_buffer[vga_index] = GetBoxDrawChar(leftrightside_ch, fore_color, back_color);
        vga_index++;

        vga_index += width;
        vga_buffer[vga_index] = GetBoxDrawChar(leftrightside_ch, fore_color, back_color);

        y++;
        vga_index = 80 * y;
        vga_index += x;
    }

    vga_buffer[vga_index] = GetBoxDrawChar(bottomleft_ch, fore_color, back_color);
    vga_index++;

    for (i = 0; i < width; i++) {
        vga_buffer[vga_index] = GetBoxDrawChar(topbottom_ch, fore_color, back_color);
        vga_index++;
    }

    vga_buffer[vga_index] = GetBoxDrawChar(bottomright_ch, fore_color, back_color);

    vga_index = 0;
}

void DrawBox(u8 boxtype,
    u16 x, u16 y,
    u16 width, u16 height,
    u8 fore_color, u8 back_color)
{
    switch (boxtype) {
    case BOX_SINGLELINE:
        DrawSimpleBox(x, y, width, height,
            fore_color, back_color,
            218, 196, 191, 179, 192, 217);
        break;

    case BOX_DOUBLELINE:
        DrawSimpleBox(x, y, width, height,
            fore_color, back_color,
            201, 205, 187, 186, 200, 188);
        break;
    }
}

void FillBox(u8 ch,
    u16 x, u16 y,
    u16 width, u16 height,
    u8 color)
{
    u32 i, j;

    for (i = 0; i < height; i++) {
        vga_index = 80 * y;
        vga_index += x;

        for (j = 0; j < width; j++) {
            vga_buffer[vga_index] = GetBoxDrawChar(ch, 0, color);
            vga_index++;
        }
        y++;
    }
}

#endif //nut UI