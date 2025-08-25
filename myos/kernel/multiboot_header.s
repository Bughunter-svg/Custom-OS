.set ALIGN,    1<<0             # align loaded modules on page boundaries
.set MEMINFO,  1<<1             # provide memory map
.set FLAGS,    ALIGN | MEMINFO  # flags for GRUB
.set MAGIC,    0x1BADB002       # magic number for GRUB
.set CHECKSUM, -(MAGIC + FLAGS) # checksum

.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM
