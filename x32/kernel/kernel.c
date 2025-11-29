#include "drivers/screen.h"

void kernel_main() {
    clear_screen();

    print_on_screen("HI\n");
    print_on_screen("Line 1\nLine 2\nLine 3\n");
    print_on_screen("text with\ttabulation\n");
    print_on_screen("text with \rr");
    set_cursor_position(20, 5);
    print_on_screen("text at postion (20, 5)");

    while (1)
    {
        asm volatile ("hlt");
    }
    
}