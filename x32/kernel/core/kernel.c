#include "drivers/video/screen.h"

void kernel_main() {
    clear_screen();

    while (1)
    {
        asm volatile ("hlt");
    }
    
}