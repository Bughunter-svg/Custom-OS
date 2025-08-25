; boot/multiboot_header.s (NASM syntax)
section .multiboot
align 4
    dd 0x1BADB002        ; magic
    dd 0x0               ; flags
    dd -(0x1BADB002)     ; checksum

