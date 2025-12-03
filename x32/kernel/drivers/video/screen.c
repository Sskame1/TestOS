#include "screen.h"
volatile char *videomem = (volatile char*)VIDEO_MEMORY;

int cursor_x = 0;
int cursor_y = 0;

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
        if (str[i] == '\n') {
            cursor_x = 0;
            cursor_y++;

            if (cursor_y >= SCREEN_HEIGHT) {
                cursor_y = SCREEN_HEIGHT - 1;
            }
        } else if (str[i] == '\t') {
            print_char_on_screen(" ", 0x0, 0x7, cursor_x, cursor_y);
            cursor_x++;
            print_char_on_screen(" ", 0x0, 0x7, cursor_x, cursor_y);
            cursor_x++;
            print_char_on_screen(" ", 0x0, 0x7, cursor_x, cursor_y);
            cursor_x++;
            print_char_on_screen(" ", 0x0, 0x7, cursor_x, cursor_y);
            cursor_x++;
        } else if (str[i] == '\r') {
            cursor_x = 0;
        }
        else {
            print_char_on_screen(&str[i], 0x0,0x7, cursor_x, cursor_y);

            cursor_x++;

            if(cursor_x >= SCREEN_WIDTH) {
                cursor_x = 0;
                cursor_y++;

                if(cursor_y >= SCREEN_HEIGHT) {
                    cursor_y = SCREEN_HEIGHT - 1;
                }
            }
        }

        i++;
    }
}

void set_cursor_position(int x, int y) {
    if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT) {
        cursor_x = x;
        cursor_y = y;
    }
}

void get_cursor_position(int *x, int *y) {
    *x = cursor_x;
    *y = cursor_y;
}

void clear_screen() {
    for (int y = 0; y < SCREEN_HEIGHT; y++) {
        for (int x = 0; x < SCREEN_WIDTH; x++) {
            print_char_on_screen(" ", 0x1, 0x7, x, y);
        }
    }
    set_cursor_position(0, 0);
}