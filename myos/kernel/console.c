#include <stdarg.h>
#include <stdbool.h>

static volatile char* vga = (char*)0xb8000;
static int row = 0, col = 0;

static void putc(char c) {
    if (c == '\n') {
        col = 0;
        row++;
        return;
    }
    int idx = (row * 80 + col) * 2;
    vga[idx] = c;
    vga[idx + 1] = 0x07; // White on black
    col++;
    if (col >= 80) { col = 0; row++; }
}

void kprint(const char* s) {
    while (*s) putc(*s++);
}
