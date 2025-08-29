#include "keyboard.h"
#include "screen.h"
#include "ports.h"
#include <stdint.h>

#define DATA_PORT 0x60
#define STATUS_PORT 0x64

static const char scancode_map[] = {
    0,0,'1','2','3','4','5','6','7','8','9','0','-','=','\b',
    '\t','q','w','e','r','t','y','u','i','o','p','[',']','\n',
    0,'a','s','d','f','g','h','j','k','l',';','\'','`',0,
    '\\','z','x','c','v','b','n','m',',','.','/',0,'*',0,' ',0
};

char get_key() {
    uint8_t scancode;
    while (!(inb(STATUS_PORT) & 0x01));
    scancode = inb(DATA_PORT);
    if (scancode & 0x80) return 0;
    if (scancode < sizeof(scancode_map)) return scancode_map[scancode];
    return '?';
}

void get_line(char* buffer, int size) {
    int i=0;
    char c;
    while (1) {
        c = get_key();
        if (!c) continue;

        if (c == '\r' || c == '\n') { buffer[i]=0; print("\n"); break; }
        else if (c == '\b') {
            if (i>0) { i--; print_char('\b'); }
        } else if (i<size-1) {
            buffer[i++]=c;
            print_char(c);
        }
    }
}
