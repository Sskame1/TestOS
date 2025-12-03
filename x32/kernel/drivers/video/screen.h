#ifndef SCREEN_H
#define SCREEN_H

// переменные
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25
#define SCREEN_SIZE (SCREEN_WIDTH * SCREEN_HEIGHT * 2)

#define VIDEO_MEMORY 0xB8000

// функции
void print_char_on_screen(const char *c, char bg, char color, int x, int y); // вывод на экран символ

void print_on_screen(const char *str); // вывод текста на экран

void set_cursor_position(int x, int y); // поставить курсор

void get_cursor_position(int *x, int *y); // получить место расположение курсора

void clear_screen(); // очистить экран

#endif 