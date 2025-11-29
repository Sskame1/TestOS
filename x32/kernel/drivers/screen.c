#include "screen.h"

void clear_screen() {
    volatile char *videomem = (volatile char*)VIDEO_MEMORY;
    for (int i = 0; i < 80 * 25 * 2; i +=2) {
        videomem[i] = ' ';
        videomem[i + 1] = 0x07;
    }
}

void print_on_screen(const char *str) {
    volatile char *videomem = (volatile char*)VIDEO_MEMORY;
    int i = 0;
    
    while (str[i] != '\0') {
        videomem[i * 2] = str[i];      // cимвол
        videomem[i * 2 + 1] = 0x07;    // атрибут(цвет)
        i++;
    }
}