#ifndef SCREEN_H
#define SCREEN_H

// переменные
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25
#define SCREEN_SIZE (SCREEN_WIDTH * SCREEN_HEIGHT * 2)

#define VIDEO_MEMORY 0xB8000

// функции
void clear_screen();
void print_on_screen();


#endif 