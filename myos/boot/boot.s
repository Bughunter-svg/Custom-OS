extern kernel_main        ; declare kernel_main exists in C code
global start

section .text
start:
    call kernel_main
    cli
    hlt

