#include "kprint.h"

static char* const VGA_MEMORY = (char*)0xb8000;
static const int VGA_WIDTH = 80;
static int cursor = 0;

void kprint(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        VGA_MEMORY[cursor * 2] = str[i];
        VGA_MEMORY[cursor * 2 + 1] = 0x07;
        cursor++;
    }
}

