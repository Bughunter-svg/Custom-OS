#include <stdint.h>

struct IDTEntry {
    uint16_t offset_low;   // lower 16 bits of handler function address
    uint16_t selector;     // code segment selector
    uint8_t  zero;         // always 0
    uint8_t  type_attr;    // type and attributes
    uint16_t offset_high;  // higher 16 bits of handler function address
} __attribute__((packed));

struct IDTPointer {
    uint16_t limit;
    uint32_t base;
} __attribute__((packed));

#define IDT_SIZE 256
struct IDTEntry idt[IDT_SIZE];
struct IDTPointer idt_ptr;

// Defined in idt_load.asm
extern void idt_load(uint32_t);

void idt_set_gate(int n, uint32_t handler, uint16_t selector, uint8_t flags) {
    idt[n].offset_low = handler & 0xFFFF;
    idt[n].selector = selector;
    idt[n].zero = 0;
    idt[n].type_attr = flags;
    idt[n].offset_high = (handler >> 16) & 0xFFFF;
}

void idt_install() {
    idt_ptr.limit = (sizeof(struct IDTEntry) * IDT_SIZE) - 1;
    idt_ptr.base = (uint32_t)&idt;
    idt_load((uint32_t)&idt_ptr);
}
