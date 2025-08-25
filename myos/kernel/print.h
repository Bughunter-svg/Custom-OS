#ifndef PRINT_H
#define PRINT_H

#include <stdint.h>

void print_char(char c, int col, int row, char attr);
void print_string(const char* str);
void clear_screen();

#endif

