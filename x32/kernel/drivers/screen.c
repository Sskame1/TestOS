#include "screen.h"
volatile char *videomem = (volatile char*)VIDEO_MEMORY;

void clear_screen() {
    for (int i = 0; i < SCREEN_SIZE; i +=2) {
        videomem[i] = ' ';
        videomem[i + 1] = 0x07;
    }
}

void print_char_on_screen(const char *c, char bg, char color, int x, int y) {
    if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) {
        return;
    }

    int position = (y * SCREEN_WIDTH + x) * 2;

    videomem[position] = *c;
    
    char attr = (bg << 4) | (color & 0x0F);

    videomem[position + 1] = attr;
}


void print_on_screen(const char *str) {
    int i = 0;
    
    while (str[i] != '\0') {
        videomem[i * 2] = str[i];      // cимвол
        videomem[i * 2 + 1] = 0x07;    // атрибут(цвет)
        i++;
    }
}