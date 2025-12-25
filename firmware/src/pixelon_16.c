/*******************************************************************************
 * Size: 16 px
 * Bpp: 1
 * Opts: --bpp 1 --size 16 --no-compress --stride 1 --align 1 --font Pixelon.ttf --range 32-127 --format lvgl -o pixelon_16.c
 ******************************************************************************/

#ifdef __has_include
    #if __has_include("lvgl.h")
        #ifndef LV_LVGL_H_INCLUDE_SIMPLE
            #define LV_LVGL_H_INCLUDE_SIMPLE
        #endif
    #endif
#endif

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif



#ifndef PIXELON_16
#define PIXELON_16 1
#endif

#if PIXELON_16

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xff, 0xff, 0xc,

    /* U+0022 "\"" */
    0xf5, 0xa0,

    /* U+0023 "#" */
    0x6c, 0x6c, 0xff, 0x6c, 0x6c, 0xff, 0x6c, 0x6c,

    /* U+0024 "$" */
    0x18, 0x18, 0x3f, 0xc0, 0x0, 0x3c, 0x0, 0x3,
    0xfc, 0x18, 0x18,

    /* U+0025 "%" */
    0xe1, 0x51, 0x29, 0x8, 0x80, 0x0, 0x40, 0x40,
    0x46, 0x4, 0x82, 0x51, 0xe0,

    /* U+0026 "&" */
    0x3c, 0x30, 0xcc, 0x3, 0x0, 0x0, 0xf, 0xfc,
    0x33, 0xc, 0xc3, 0x0, 0x3, 0xcc,

    /* U+0027 "'" */
    0xd8,

    /* U+0028 "(" */
    0x3b, 0x6d, 0xb6, 0xdb, 0x62,

    /* U+0029 ")" */
    0xc4, 0x92, 0x49, 0x24, 0x9c,

    /* U+002A "*" */
    0xcc, 0x80, 0x33,

    /* U+002B "+" */
    0x18, 0x18, 0x18, 0xff, 0x18, 0x18, 0x18, 0x18,

    /* U+002C "," */
    0xd8,

    /* U+002D "-" */
    0xfc,

    /* U+002E "." */
    0xc0,

    /* U+002F "/" */
    0x2, 0x0, 0x0, 0x20, 0x82, 0x8, 0x20, 0x0,
    0x2, 0x0,

    /* U+0030 "0" */
    0x3c, 0xc3, 0xc3, 0xc7, 0xc3, 0xdb, 0xc3, 0xe3,
    0xc3, 0x0, 0x3c,

    /* U+0031 "1" */
    0xe3, 0x18, 0xc6, 0x31, 0x8c, 0x63, 0x3e,

    /* U+0032 "2" */
    0x3c, 0x0, 0xc3, 0x4, 0x0, 0x18, 0x0, 0x20,
    0xc0, 0xc0, 0xff,

    /* U+0033 "3" */
    0x3c, 0xc3, 0x3, 0x3, 0x0, 0x3c, 0x3, 0x3,
    0xc3, 0x0, 0x3c,

    /* U+0034 "4" */
    0xc, 0xc, 0x1c, 0x2c, 0xcc, 0xcc, 0xcc, 0xff,
    0xc, 0xc, 0x1f,

    /* U+0035 "5" */
    0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0x3c, 0x3, 0x3,
    0xc3, 0x0, 0x3c,

    /* U+0036 "6" */
    0x1c, 0x0, 0x20, 0xc0, 0x0, 0x3c, 0xc3, 0xc3,
    0xc3, 0x0, 0x3c,

    /* U+0037 "7" */
    0xff, 0xc3, 0xc3, 0x4, 0x0, 0x18, 0x20, 0x20,
    0x20, 0x20, 0x20,

    /* U+0038 "8" */
    0x3c, 0xc3, 0xc3, 0xc3, 0x0, 0x3c, 0xc3, 0xc3,
    0xc3, 0x0, 0x3c,

    /* U+0039 "9" */
    0x3c, 0x0, 0xc3, 0xc3, 0xc3, 0x3f, 0x3, 0x3,
    0x4, 0x0, 0x38,

    /* U+003A ":" */
    0xc0, 0xc0,

    /* U+003B ";" */
    0xc0, 0xd8,

    /* U+003C "<" */
    0xc, 0x2, 0x30, 0x0, 0x80, 0x3,

    /* U+003D "=" */
    0xfc, 0x0, 0x3f,

    /* U+003E ">" */
    0xc0, 0x2, 0x3, 0x0, 0x80, 0x30,

    /* U+003F "?" */
    0x3c, 0x0, 0xc3, 0x4, 0x0, 0x18, 0x0, 0x20,
    0x0, 0x0, 0x20,

    /* U+0040 "@" */
    0x3f, 0x98, 0xf, 0x1, 0xe3, 0xbc, 0x37, 0xb6,
    0xf0, 0xc6, 0x3c, 0xc0, 0x0, 0x0, 0xfe, 0x0,

    /* U+0041 "A" */
    0x3c, 0x0, 0xc3, 0xc3, 0xc3, 0xff, 0xc3, 0xc3,
    0xc3, 0xc3, 0xc3,

    /* U+0042 "B" */
    0xfc, 0xc3, 0xc3, 0xc3, 0xc0, 0xfc, 0xc3, 0xc3,
    0xc3, 0xc0, 0xfc,

    /* U+0043 "C" */
    0x3c, 0x0, 0xc3, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0,
    0xc3, 0x0, 0x3c,

    /* U+0044 "D" */
    0xfc, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc0, 0xfc,

    /* U+0045 "E" */
    0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xf8, 0xc0, 0xc0,
    0xc0, 0xc0, 0xff,

    /* U+0046 "F" */
    0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xf8, 0xc0, 0xc0,
    0xc0, 0xc0, 0xc0,

    /* U+0047 "G" */
    0x3c, 0xc3, 0xc0, 0xc0, 0xc0, 0xdf, 0xc3, 0xc3,
    0xc3, 0x0, 0x3c,

    /* U+0048 "H" */
    0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xff, 0xc3, 0xc3,
    0xc3, 0xc3, 0xc3,

    /* U+0049 "I" */
    0xfb, 0x18, 0xc6, 0x31, 0x8c, 0x63, 0x3e,

    /* U+004A "J" */
    0x3f, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3,
    0xc3, 0x0, 0x3c,

    /* U+004B "K" */
    0xc3, 0xc0, 0xc4, 0xd8, 0xc0, 0xe0, 0xc0, 0xd8,
    0xc4, 0xc0, 0xc3,

    /* U+004C "L" */
    0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0,
    0xc0, 0xc0, 0xff,

    /* U+004D "M" */
    0xe0, 0xf8, 0xf, 0x6d, 0xe2, 0x3c, 0x7, 0x80,
    0xf0, 0x1e, 0x3, 0xc0, 0x78, 0xf, 0x1, 0x80,

    /* U+004E "N" */
    0xe3, 0xc3, 0xdb, 0xc7, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3, 0xc3,

    /* U+004F "O" */
    0x3c, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0x0, 0x3c,

    /* U+0050 "P" */
    0xfc, 0xc3, 0xc3, 0xc3, 0xc0, 0xfc, 0xc0, 0xc0,
    0xc0, 0xc0, 0xc0,

    /* U+0051 "Q" */
    0x3c, 0x0, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xdb,
    0xc4, 0x0, 0x3b,

    /* U+0052 "R" */
    0xfc, 0xc3, 0xc3, 0xc3, 0xc0, 0xfc, 0xd8, 0xd8,
    0xc4, 0xc0, 0xc3,

    /* U+0053 "S" */
    0x3c, 0xc3, 0xc0, 0xc0, 0x0, 0x3c, 0x3, 0x3,
    0xc3, 0x0, 0x3c,

    /* U+0054 "T" */
    0xff, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18,

    /* U+0055 "U" */
    0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0x0, 0x3c,

    /* U+0056 "V" */
    0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0x24, 0x0, 0x18,

    /* U+0057 "W" */
    0xc0, 0x38, 0x7, 0x0, 0xe0, 0x1c, 0x3, 0x80,
    0x70, 0xe, 0x21, 0xdb, 0x20, 0x0, 0x83, 0x0,

    /* U+0058 "X" */
    0xc3, 0xc3, 0xc3, 0x24, 0x0, 0x18, 0x0, 0x24,
    0xc3, 0xc3, 0xc3,

    /* U+0059 "Y" */
    0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x24, 0x18, 0x18,
    0x18, 0x18, 0x18,

    /* U+005A "Z" */
    0xff, 0x3, 0x3, 0x4, 0x0, 0x18, 0x0, 0x20,
    0xc0, 0xc0, 0xff,

    /* U+005B "[" */
    0xfb, 0x6d, 0xb6, 0xdb, 0x6d, 0xc0,

    /* U+005C "\\" */
    0x80, 0x0, 0x2, 0x2, 0x2, 0x2, 0x2, 0x0,
    0x0, 0x8,

    /* U+005D "]" */
    0xf3, 0x33, 0x33, 0x33, 0x33, 0x33, 0x3f,

    /* U+005E "^" */
    0x18, 0x0, 0x24, 0x0, 0xc3,

    /* U+005F "_" */
    0xff,

    /* U+0060 "`" */
    0xa4,

    /* U+0061 "a" */
    0xfc, 0x3, 0x3, 0x3f, 0x3, 0xc3, 0x3, 0x3f,

    /* U+0062 "b" */
    0xc0, 0xc0, 0xc0, 0xfc, 0xc0, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3, 0xfc,

    /* U+0063 "c" */
    0x3c, 0x0, 0xc3, 0xc0, 0xc0, 0xc3, 0x0, 0x3c,

    /* U+0064 "d" */
    0x3, 0x3, 0x3, 0x3f, 0x3, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3, 0x3f,

    /* U+0065 "e" */
    0x3c, 0x0, 0xc3, 0xff, 0xc0, 0xc0, 0xc0, 0x3c,

    /* U+0066 "f" */
    0x1f, 0x0, 0x60, 0xfc, 0x60, 0x60, 0x60, 0x60,
    0x60, 0x60, 0x60,

    /* U+0067 "g" */
    0x3f, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x3, 0x3f,
    0x3, 0x3, 0xfc,

    /* U+0068 "h" */
    0xc0, 0xc0, 0xc0, 0xfc, 0xc0, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3, 0xc3,

    /* U+0069 "i" */
    0xc3, 0xff, 0xfc,

    /* U+006A "j" */
    0x18, 0x0, 0x31, 0x8c, 0x63, 0x18, 0xc6, 0x30,
    0x70,

    /* U+006B "k" */
    0xc3, 0xc, 0x31, 0xc3, 0x6e, 0x30, 0xdb, 0xc,
    0x40,

    /* U+006C "l" */
    0xff, 0xff, 0xfc,

    /* U+006D "m" */
    0xff, 0x99, 0x83, 0x31, 0xe6, 0x3c, 0xc7, 0x98,
    0xf3, 0x1e, 0x63,

    /* U+006E "n" */
    0xfc, 0xc0, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,

    /* U+006F "o" */
    0x3c, 0x0, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x3c,

    /* U+0070 "p" */
    0xfc, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc0, 0xfc,
    0xc0, 0xc0, 0xc0,

    /* U+0071 "q" */
    0x3f, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x3, 0x3f,
    0x3, 0x3, 0x3,

    /* U+0072 "r" */
    0x3c, 0xc, 0x30, 0xc3, 0xc, 0x30,

    /* U+0073 "s" */
    0x3f, 0x0, 0xc0, 0x3c, 0x0, 0x3, 0x0, 0xfc,

    /* U+0074 "t" */
    0x61, 0x86, 0x3f, 0x61, 0x86, 0x18, 0x60, 0x1,
    0xc0,

    /* U+0075 "u" */
    0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x0, 0x3c,

    /* U+0076 "v" */
    0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x24, 0x0, 0x18,

    /* U+0077 "w" */
    0xc0, 0x78, 0x8f, 0x11, 0xe2, 0x3c, 0x47, 0x88,
    0xc0, 0x1, 0xdc,

    /* U+0078 "x" */
    0xc3, 0x0, 0x24, 0x18, 0x0, 0x24, 0x0, 0xc3,

    /* U+0079 "y" */
    0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x3, 0x3f,
    0x3, 0x0, 0xfc,

    /* U+007A "z" */
    0xfb, 0x0, 0x4, 0x0, 0x18, 0x20, 0x0, 0xdf,

    /* U+007B "{" */
    0xc, 0x82, 0x8, 0x20, 0x8c, 0x8, 0x20, 0x82,
    0x8, 0xc,

    /* U+007C "|" */
    0xff, 0xff, 0xff, 0xfc,

    /* U+007D "}" */
    0xc0, 0x82, 0x8, 0x20, 0x80, 0xc8, 0x20, 0x82,
    0x8, 0xc0,

    /* U+007E "~" */
    0x20, 0x0, 0xdb, 0x0, 0x4
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 77, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 50, .box_w = 2, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 4, .adv_w = 88, .box_w = 4, .box_h = 3, .ofs_x = 1, .ofs_y = 8},
    {.bitmap_index = 6, .adv_w = 150, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 14, .adv_w = 150, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 25, .adv_w = 162, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 38, .adv_w = 175, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 52, .adv_w = 50, .box_w = 2, .box_h = 3, .ofs_x = 1, .ofs_y = 8},
    {.bitmap_index = 53, .adv_w = 75, .box_w = 3, .box_h = 13, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 58, .adv_w = 75, .box_w = 3, .box_h = 13, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 63, .adv_w = 100, .box_w = 6, .box_h = 4, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 66, .adv_w = 150, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 74, .adv_w = 50, .box_w = 2, .box_h = 3, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 75, .adv_w = 125, .box_w = 6, .box_h = 1, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 76, .adv_w = 50, .box_w = 2, .box_h = 1, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 77, .adv_w = 137, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 87, .adv_w = 150, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 98, .adv_w = 100, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 105, .adv_w = 150, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 116, .adv_w = 150, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 127, .adv_w = 150, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 138, .adv_w = 150, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 149, .adv_w = 150, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 160, .adv_w = 150, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 171, .adv_w = 150, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 182, .adv_w = 150, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 193, .adv_w = 50, .box_w = 2, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 195, .adv_w = 50, .box_w = 2, .box_h = 7, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 197, .adv_w = 100, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 203, .adv_w = 125, .box_w = 6, .box_h = 4, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 206, .adv_w = 100, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 212, .adv_w = 150, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 223, .adv_w = 200, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 239, .adv_w = 150, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 250, .adv_w = 150, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 261, .adv_w = 150, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 272, .adv_w = 150, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 283, .adv_w = 150, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 294, .adv_w = 150, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 305, .adv_w = 150, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 316, .adv_w = 150, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 327, .adv_w = 100, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 334, .adv_w = 150, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 345, .adv_w = 150, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 356, .adv_w = 150, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 367, .adv_w = 200, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 383, .adv_w = 150, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 394, .adv_w = 150, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 405, .adv_w = 150, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 416, .adv_w = 150, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 427, .adv_w = 150, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 438, .adv_w = 150, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 449, .adv_w = 150, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 460, .adv_w = 150, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 471, .adv_w = 150, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 482, .adv_w = 200, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 498, .adv_w = 150, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 509, .adv_w = 150, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 520, .adv_w = 150, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 531, .adv_w = 75, .box_w = 3, .box_h = 14, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 537, .adv_w = 137, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 547, .adv_w = 75, .box_w = 4, .box_h = 14, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 554, .adv_w = 150, .box_w = 8, .box_h = 5, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 559, .adv_w = 150, .box_w = 8, .box_h = 1, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 560, .adv_w = 100, .box_w = 2, .box_h = 3, .ofs_x = 2, .ofs_y = 12},
    {.bitmap_index = 561, .adv_w = 150, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 569, .adv_w = 150, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 580, .adv_w = 150, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 588, .adv_w = 150, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 599, .adv_w = 150, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 607, .adv_w = 124, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 618, .adv_w = 150, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 629, .adv_w = 150, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 640, .adv_w = 50, .box_w = 2, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 643, .adv_w = 49, .box_w = 5, .box_h = 14, .ofs_x = -2, .ofs_y = -3},
    {.bitmap_index = 652, .adv_w = 125, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 661, .adv_w = 50, .box_w = 2, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 664, .adv_w = 200, .box_w = 11, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 675, .adv_w = 150, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 683, .adv_w = 150, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 691, .adv_w = 150, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 702, .adv_w = 150, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 713, .adv_w = 125, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 719, .adv_w = 150, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 727, .adv_w = 125, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 736, .adv_w = 150, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 744, .adv_w = 150, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 752, .adv_w = 200, .box_w = 11, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 763, .adv_w = 150, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 771, .adv_w = 150, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 782, .adv_w = 150, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 790, .adv_w = 100, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 800, .adv_w = 50, .box_w = 2, .box_h = 15, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 804, .adv_w = 100, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 814, .adv_w = 150, .box_w = 8, .box_h = 5, .ofs_x = 1, .ofs_y = 2}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Pair left and right glyphs for kerning*/
static const uint8_t kern_pair_glyph_ids[] =
{
    72, 75,
    82, 75,
    90, 75
};

/* Kerning between the respective left and right glyphs
 * 4.4 format which needs to scaled with `kern_scale`*/
static const int8_t kern_pair_values[] =
{
    51, 51, 51
};

/*Collect the kern pair's data in one place*/
static const lv_font_fmt_txt_kern_pair_t kern_pairs =
{
    .glyph_ids = kern_pair_glyph_ids,
    .values = kern_pair_values,
    .pair_cnt = 3,
    .glyph_ids_size = 0
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_pairs,
    .kern_scale = 16,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif

};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t pixelon_16 = {
#else
lv_font_t pixelon_16 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 18,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .static_bitmap = 0,
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if PIXELON_16*/
