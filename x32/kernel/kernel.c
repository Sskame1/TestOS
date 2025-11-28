#include "drivers/screen.h"

void kernel_main() {

    test_screen('r');
    delay();
    test_screen('b');
    delay();
    test_screen('r');
    delay();
    test_screen('b');
    delay();
    test_screen('r');
    
    // print_string("Hello World! from testOS kernel! Screen driver works!");
    // print_string - пока не реализован
    while(1);
}