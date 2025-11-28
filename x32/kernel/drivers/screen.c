#include "screen.h"

// константы
#define VIDEO_MEMORY 0xB8000
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25


void test_screen() {
    volatile unsigned short* video_memory = (volatile unsigned short*)VIDEO_MEMORY;
    
    for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT + 3; i++) {
        if (i % 2 == 0) {
            video_memory[i] = 0x40;
        } else {
            video_memory[i] = 0x20;
        }
    }
}