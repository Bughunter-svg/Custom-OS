#include <stdint.h>
#include "print.h"

extern void isr_handler();

__attribute__((interrupt))
void keyboard_handler() {
    unsigned char scancode;
    asm volatile ("inb %1, %0" : "=a"(scancode) : "Nd"(0x60));

    // Convert scancode to ASCII (simple for now: just numbers/letters)
    if (scancode == 0x1E) print_string("a");
    if (scancode == 0x30) print_string("b");
    if (scancode == 0x2E) print_string("c");
    if (scancode == 0x20) print_string("d");
    if (scancode == 0x12) print_string("e");

    // Send end of interrupt (EOI) to PIC
    asm volatile ("movb $0x20, %al; outb %al, $0x20");
}
