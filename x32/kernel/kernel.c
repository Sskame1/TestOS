void clear_screen() {
    volatile char *videomem = (volatile char*)0xB8000;
    for (int i = 0; i < 80 * 25 * 2; i +=2) {
        videomem[i] = ' ';
        videomem[i + 1] = 0x07;
    }
}

void print_string(const char *str) {
    volatile char *videomem = (volatile char*)0xB8000;
    int i = 0;
    
    while (str[i] != '\0') {
        videomem[i * 2] = str[i];      // cимвол
        videomem[i * 2 + 1] = 0x07;    // атрибут(цвет)
        i++;
    }
}

void kernel_main() {
    clear_screen();
    print_string("HI");

    while (1)
    {
        asm volatile ("hlt");
    }
    
}