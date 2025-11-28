void clear_screen() {
    volatile unsigned short *video_memory = (volatile unsigned short *)0xB8000;
    int screen_size = 80 * 25;
    
    unsigned short cell = 0x20 | (0x27 << 8);
    for (int i = 0; i < screen_size; i++) {
        video_memory[i] = cell;
    }
}

void kernel_main() {
    clear_screen();

    while(1);
}