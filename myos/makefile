ASM = nasm
CC = gcc
LD = ld

CFLAGS = -m32 -ffreestanding -nostdlib -fno-exceptions -fno-pic -Wall -Wextra

# Add keyboard.o and ports.o to this list
OBJS = boot/boot.o kernel/kernel.o kernel/screen.o kernel/ports.o kernel/keyboard.o

all: kernel.bin

boot/boot.o: boot/boot.s
	$(ASM) -f elf32 $< -o $@

kernel/kernel.o: kernel/kernel.c
	$(CC) $(CFLAGS) -c $< -o $@

kernel/screen.o: kernel/screen.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to compile ports.c
kernel/ports.o: kernel/ports.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to compile keyboard.c
kernel/keyboard.o: kernel/keyboard.c
	$(CC) $(CFLAGS) -c $< -o $@

# Update the linker rule to use the OBJS variable
kernel.bin: $(OBJS)
	$(LD) -m elf_i386 -T linker.ld -o $@ $^

iso: kernel.bin
	mkdir -p isodir/boot/grub
	cp kernel.bin isodir/boot/kernel.bin
	cp boot/grub.cfg isodir/boot/grub/grub.cfg
	grub-mkrescue -o myos.iso isodir

run: iso
	qemu-system-i386 -cdrom myos.iso

clean:
	rm -rf boot/*.o kernel/*.o kernel.bin isodir myos.iso
