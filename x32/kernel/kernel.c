#include "drivers/screen.h"

void kernel_main() {
    clear_screen();

    print_char_on_screen("H", 0x1, 0x4, 5, 5);
    print_char_on_screen("I", 0x1, 0x2, 5, 6);


    print_on_screen("HI");

    while (1)
    {
        asm volatile ("hlt");
    }
    
}