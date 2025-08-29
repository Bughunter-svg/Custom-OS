#ifndef SCREEN_H
#define SCREEN_H

#define VIDEO_MEMORY_ADDRESS 0xB8000
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25
#define WHITE_ON_BLACK 0x0F

void clear_screen();
void print(char* message);
void print_at(char* message, int col, int row);
void print_char(char c);   // MUST be public

#endif
