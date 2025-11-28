#include "screen.h"

// константы
#define VIDEO_MEMORY 0xB8000
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25
#define SCREEN_SIZE SCREEN_WIDTH * SCREEN_HEIGHT


void delay() {
    for (volatile int i = 0; i < 10000000; i++);
}

void test_screen(char invColor) {
    volatile unsigned short* video_memory = (volatile unsigned short*)VIDEO_MEMORY;
    
    if (invColor == 'r') {
        for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT + 3; i++) {
            if (i % 2 == 0) {
                video_memory[i] = 0x40;
            } else {
                video_memory[i] = 0x20;
            }
        }
    } else {
        for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT + 3; i++) {
            if (i % 2 == 0) {
                video_memory[i] = 0x20;
            } else {
                video_memory[i] = 0x40;
            }
        }
    }
}

void clear_screen() {
    volatile unsigned short* video_memory = (volatile unsigned short*)VIDEO_MEMORY;

    for (int i = 0; i < SCREEN_SIZE + 3; i++) {
        video_memory[i] = 0x01;
    }
}