section .multiboot
    align 4
    dd 0x1BADB002        ; magic number
    dd 0x0               ; flags
    dd -(0x1BADB002)     ; checksum

section .text
global _start
_start:
    extern kmain
    call kmain

.loop:
    hlt
    jmp .loop

