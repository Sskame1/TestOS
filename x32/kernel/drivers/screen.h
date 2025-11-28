#ifndef SCREEN_H
#define SCREEN_H

void clear_screen();

void test_screen();

void put_char(char c, unsigned char attribute, int x, int y);

void print_string(const char* str);

#endif