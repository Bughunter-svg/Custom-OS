// Prevents C++ name mangling if you ever switch to C++
void kernel_main(void) {
    const char *msg = "Hello Harshith, I hope you'll build me quick";
    char *video = (char*) 0xb8000; // VGA text buffer

    for (int i = 0; msg[i] != '\0'; i++) {
        video[i * 2] = msg[i];
        video[i * 2 + 1] = 0x07; // White on black
    }

    // Halt CPU so it doesn’t run into garbage
    for (;;) {
        __asm__ __volatile__("hlt");
    }
}

