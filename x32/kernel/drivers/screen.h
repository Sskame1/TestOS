#ifndef SCREEN_H
#define SCREEN_H

void delay();

void clear_screen();

void test_screen(char invColor);

void put_char(char c, unsigned char attribute, int x, int y);

void print_string(const char* str);

#endif