#include "print.h"
#include <stdint.h>

#define VIDEO_ADDRESS 0xb8000
#define MAX_ROWS 25
#define MAX_COLS 80

// VGA buffer
uint16_t* vga_buffer = (uint16_t*)VIDEO_ADDRESS;

// current cursor position
int cursor_row = 0;
int cursor_col = 0;

void print_char(char c, int col, int row, char attr) {
    int offset;
    if (col >= 0 && row >= 0) {
        offset = row * MAX_COLS + col;
    } else {
        offset = cursor_row * MAX_COLS + cursor_col;
    }

    uint16_t entry = ((uint16_t)attr << 8) | (uint8_t)c;
    vga_buffer[offset] = entry;

    cursor_col++;
    if (cursor_col >= MAX_COLS) {
        cursor_col = 0;
        cursor_row++;
    }
}

void print_string(const char* str) {
    int i = 0;
    while (str[i] != '\0') {
        print_char(str[i], -1, -1, 0x0F);  // white on black
        i++;
    }
}

void clear_screen() {
    for (int row = 0; row < MAX_ROWS; row++) {
        for (int col = 0; col < MAX_COLS; col++) {
            int offset = row * MAX_COLS + col;
            vga_buffer[offset] = (0x0F << 8) | ' ';
        }
    }
    cursor_row = 0;
    cursor_col = 0;
}

