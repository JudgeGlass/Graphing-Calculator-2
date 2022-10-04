#ifndef __FONT_HPP__
#define __FONT_HPP__

#include <string>
#include <algorithm>
#include <screen.hpp>

// javl.github.io/image2cpp/
// plain bytes, Horizontal 1bit per pixel

static const uint8_t fontArray[] = {
// 'FONT_PICO', 256x24px
0x7c, 0xfc, 0x7c, 0xfc, 0xfe, 0xfe, 0x7c, 0xc6, 0xfc, 0x06, 0xc6, 0xc0, 0xc6, 0xc6, 0x7c, 0xfc, 
0x7c, 0xfc, 0x7c, 0xfc, 0xc6, 0xc6, 0xc6, 0xc6, 0x84, 0xfe, 0x30, 0x20, 0x10, 0x00, 0x00, 0x00, 
0xc6, 0xc6, 0xc6, 0xc6, 0xc0, 0xc0, 0xc6, 0xc6, 0x30, 0x06, 0xc6, 0xc0, 0xee, 0xc6, 0xc6, 0xc6, 
0xc6, 0xc6, 0xc6, 0x30, 0xc6, 0xc6, 0xc6, 0x6c, 0xcc, 0x06, 0x30, 0xa8, 0x38, 0x00, 0x00, 0x00, 
0xc6, 0xc6, 0xc0, 0xc6, 0xc0, 0xc0, 0xc0, 0xc6, 0x30, 0x06, 0xcc, 0xc0, 0xd6, 0xe6, 0xc6, 0xc6, 
0xc6, 0xc6, 0xc0, 0x30, 0xc6, 0xc6, 0xc6, 0x38, 0x78, 0x0c, 0x30, 0x70, 0x6c, 0x00, 0x00, 0x00, 
0xfe, 0xfc, 0xc0, 0xc6, 0xf0, 0xf0, 0xde, 0xfe, 0x30, 0x06, 0xf8, 0xc0, 0xc6, 0xd6, 0xc6, 0xfc, 
0xc6, 0xfc, 0x7c, 0x30, 0xc6, 0xc6, 0xc6, 0x10, 0x30, 0x18, 0x30, 0x70, 0xc6, 0x00, 0x00, 0x00, 
0xc6, 0xc6, 0xc0, 0xc6, 0xc0, 0xc0, 0xc6, 0xc6, 0x30, 0x06, 0xcc, 0xc0, 0xc6, 0xce, 0xc6, 0xc0, 
0xc6, 0xc6, 0x06, 0x30, 0xc6, 0x6c, 0xd6, 0x38, 0x30, 0x30, 0x30, 0xa8, 0x82, 0x00, 0x00, 0x00, 
0xc6, 0xc6, 0xc6, 0xc6, 0xc0, 0xc0, 0xc6, 0xc6, 0x30, 0xc6, 0xc6, 0xc0, 0xc6, 0xc6, 0xc6, 0xc0, 
0xcc, 0xc6, 0xc6, 0x30, 0xc6, 0x38, 0xfe, 0x6c, 0x30, 0x60, 0x30, 0x20, 0x00, 0x00, 0x00, 0x00, 
0xc6, 0xfc, 0x7c, 0xfc, 0xfe, 0xc0, 0x7c, 0xc6, 0xfc, 0x7c, 0xc6, 0xfe, 0xc6, 0xc6, 0x7c, 0xc0, 
0x76, 0xc6, 0x7c, 0x30, 0x7c, 0x10, 0x6c, 0xc6, 0x30, 0xfe, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x7c, 0x10, 0x7c, 0x7c, 0xc6, 0xfe, 0x7c, 0xfe, 0x7c, 0x7c, 0x00, 0x00, 0x30, 0x78, 0x30, 0x6c, 
0x00, 0x00, 0x00, 0x06, 0xc0, 0xc6, 0x1c, 0x70, 0x0c, 0x60, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 
0xc6, 0x30, 0xc6, 0xc6, 0xc6, 0xc0, 0xc6, 0x06, 0xc6, 0xc6, 0x00, 0x00, 0x78, 0xcc, 0x10, 0x24, 
0x00, 0x10, 0x00, 0x0c, 0x60, 0xcc, 0x30, 0x18, 0x18, 0x30, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 
0xc6, 0x70, 0x0c, 0x06, 0xc6, 0xc0, 0xc0, 0x0c, 0xc6, 0xc6, 0x00, 0x00, 0x78, 0x0c, 0x20, 0x48, 
0x00, 0x10, 0x7c, 0x18, 0x30, 0x18, 0x60, 0x0c, 0x30, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0xd6, 0x30, 0x18, 0x0c, 0xfe, 0xfc, 0xfc, 0x18, 0x7c, 0x7e, 0x00, 0x00, 0x30, 0x18, 0x00, 0x00, 
0x7c, 0x7c, 0x00, 0x30, 0x18, 0x30, 0x60, 0x0c, 0x60, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0xc6, 0x30, 0x30, 0x06, 0x06, 0x06, 0xc6, 0x30, 0xc6, 0x06, 0x00, 0x30, 0x30, 0x30, 0x00, 0x00, 
0x00, 0x10, 0x7c, 0x60, 0x0c, 0x60, 0x60, 0x0c, 0x30, 0x18, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 
0xc6, 0x30, 0x60, 0xc6, 0x06, 0xc6, 0xc6, 0x30, 0xc6, 0xc6, 0x30, 0x10, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x10, 0x00, 0xc0, 0x06, 0xc6, 0x30, 0x18, 0x18, 0x30, 0x30, 0x10, 0x00, 0x00, 0x00, 0x00, 
0x7c, 0xfc, 0xfe, 0x7c, 0x06, 0x7c, 0x7c, 0x30, 0x7c, 0x7c, 0x30, 0x20, 0x30, 0x30, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x80, 0x02, 0x86, 0x1c, 0x70, 0x0c, 0x60, 0x30, 0x20, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x60, 0x00, 0x0c, 0x00, 0x1c, 0x3e, 0x60, 0x18, 0x0c, 0x60, 0x38, 0x00, 0x00, 0x00, 0x7c, 
0x3e, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x66, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x7c, 0x60, 0x3c, 0x7c, 0x3c, 0x30, 0x66, 0x60, 0x00, 0x00, 0x60, 0x18, 0xec, 0x7c, 0x3c, 0x66, 
0x66, 0x7c, 0x7e, 0xfc, 0x66, 0x66, 0xc6, 0x66, 0x66, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x06, 0x7c, 0x60, 0xcc, 0x66, 0x7c, 0x66, 0x7c, 0x38, 0x0c, 0x6c, 0x18, 0xfe, 0x66, 0x66, 0x66, 
0x66, 0x66, 0xc0, 0x30, 0x66, 0x66, 0xd6, 0x3c, 0x66, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x7e, 0x66, 0x60, 0xcc, 0x7e, 0x30, 0x3e, 0x66, 0x18, 0x0c, 0x78, 0x18, 0xfe, 0x66, 0x66, 0x7c, 
0x3e, 0x60, 0x7c, 0x30, 0x66, 0x66, 0xfe, 0x18, 0x3e, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0xc6, 0x66, 0x60, 0xcc, 0x60, 0x30, 0x06, 0x66, 0x18, 0x0c, 0x6c, 0x18, 0xd6, 0x66, 0x66, 0x60, 
0x06, 0x60, 0x06, 0x30, 0x66, 0x3c, 0x7c, 0x3c, 0x0c, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x7e, 0x7c, 0x3c, 0x7c, 0x3c, 0x30, 0x7c, 0x66, 0x3c, 0x78, 0x66, 0x3c, 0xc6, 0x66, 0x3c, 0x60, 
0x06, 0x60, 0xfc, 0x1c, 0x3e, 0x18, 0x6c, 0x66, 0x78, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


#endif