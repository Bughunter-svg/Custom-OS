#include "screen.h"
#include "keyboard.h"

#define LINE_SIZE 128

void kmain() {
    char line[LINE_SIZE];
    clear_screen();
    print("Welcome to Custom-OS Shell!\n");

    while(1) {
        print("> ");
        get_line(line, LINE_SIZE);

        if (line[0]==0) continue;

        if (line[0]=='h' && line[1]=='e' && line[2]=='l' && line[3]=='p') {
            print("Commands:\nhelp - show this\nclear - clear screen\necho <text> - print text\n");
        } else if (line[0]=='c' && line[1]=='l' && line[2]=='e' && line[3]=='a' && line[4]=='r') {
            clear_screen();
        } else if (line[0]=='e' && line[1]=='c' && line[2]=='h' && line[3]=='o' && line[4]==' ') {
            print(line+5); print("\n");
        } else {
            print("Unknown command\n");
        }
    }
}
