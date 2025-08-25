#include "console.h"

#define VGA_ADDRESS 0xB8000
#define VGA_WIDTH 80
#define VGA_HEIGHT 25

unsigned short* vga_buffer = (unsigned short*)VGA_ADDRESS;
int cursor_x = 0;
int cursor_y = 0;

void console_clear() {
    for (int y = 0; y < VGA_HEIGHT; y++) {
        for (int x = 0; x < VGA_WIDTH; x++) {
            vga_buffer[y * VGA_WIDTH + x] = (0x07 << 8) | ' ';
        }
    }
    cursor_x = 0;
    cursor_y = 0;
}

void console_putc(char c) {
    if (c == '\n') {
        cursor_x = 0;
        cursor_y++;
    } else {
        vga_buffer[cursor_y * VGA_WIDTH + cursor_x] = (0x07 << 8) | c;
        cursor_x++;
        if (cursor_x >= VGA_WIDTH) {
            cursor_x = 0;
            cursor_y++;
        }
    }

    if (cursor_y >= VGA_HEIGHT) {
        cursor_y = 0;  // simple wrap (no scroll yet)
    }
}

