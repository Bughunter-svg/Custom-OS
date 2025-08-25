ENTRY(start)

SECTIONS
{
    . = 1M;                /* Load kernel at 1MB */

    .multiboot_header :
    {
        *(.multiboot_header)
    }

    .text :
    {
        *(.text*)
    }

    .rodata :
    {
        *(.rodata*)
    }

    .data :
    {
        *(.data*)
    }

    .bss :
    {
        *(.bss*)
        *(COMMON)
    }
}

