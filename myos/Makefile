# Build 32-bit kernel

CC = gcc
LD = ld
CFLAGS = -m32 -ffreestanding -nostdlib -fno-pie -fno-stack-protector -Wall -Wextra

OBJS = boot/multiboot_header.o boot/boot.o kernel/kernel.o kernel/print.o

all: os-image.bin

boot/multiboot_header.o: boot/multiboot_header.s
	nasm -f elf32 boot/multiboot_header.s -o boot/multiboot_header.o


boot/boot.o: boot/boot.s
	nasm -f elf32  boot/boot.s -o boot/boot.o

kernel/kernel.o: kernel/kernel.c
	$(CC) $(CFLAGS) -c -o $@ $<

kernel/print.o: kernel/print.c
	$(CC) $(CFLAGS) -c -o $@ $<

os-image.bin: linker.ld boot/multiboot_header.o boot/boot.o kernel/kernel.o kernel/print.o
	 ld -m elf_i386 -T linker.ld -o os-image.bin boot/multiboot_header.o boot/boot.o kernel/kernel.o kernel/print.o


run: os-image.bin
	qemu-system-i386 -kernel os-image.bin

clean:
	rm -f $(OBJS) os-image.bin
