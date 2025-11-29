#include "drivers/screen.h"

void kernel_main() {
    clear_screen();
    print_on_screen("HI");

    while (1)
    {
        asm volatile ("hlt");
    }
    
}