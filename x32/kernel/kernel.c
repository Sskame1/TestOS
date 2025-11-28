#include "drivers/screen.h"

void kernel_main() {
    test_screen('r');
    delay();
    clear_screen();

    // print_string("Hello World! from testOS kernel! Screen driver works!");
    // print_string - пока не реализован
    while(1);
}