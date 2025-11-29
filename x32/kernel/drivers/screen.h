#ifndef SCREEN_H
#define SCREEN_H

// переменные
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25
#define SCREEN_SIZE (SCREEN_WIDTH * SCREEN_HEIGHT * 2)

#define VIDEO_MEMORY 0xB8000

// функции
void print_char_on_screen(const char *c, char bg, char color, int x, int y);

void print_on_screen(const char *str);

void set_cursor_position(int x, int y);

void get_cursor_position(int *x, int *y);

void clear_screen();

#endif 