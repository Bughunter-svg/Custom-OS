CC = gcc
LD = ld
CFLAGS = -m32 -ffreestanding -fno-pic -fno-pie -O2 -Wall -Wextra
LDFLAGS = -m elf_i386 -T kernel/linker.ld -nostdlib

all: iso/myos.iso

kernel/kernel.elf: kernel/multiboot_header.o kernel/kernel.o kernel/linker.ld
	$(LD) $(LDFLAGS) -o $@ kernel/multiboot_header.o kernel/kernel.o

iso/myos.iso: kernel/kernel.elf boot/grub/grub.cfg
	mkdir -p iso/boot/grub
	cp kernel/kernel.elf iso/boot/
	cp boot/grub/grub.cfg iso/boot/grub/
	grub-mkrescue -o iso/myos.iso iso/

run: iso/myos.iso
	qemu-system-i386 -cdrom iso/myos.iso

clean:
	rm -rf kernel/*.o kernel/*.elf iso

kernel/multiboot_header.o: kernel/multiboot_header.s
	$(CC) -m32 -c $< -o $@
