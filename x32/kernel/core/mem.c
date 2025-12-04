#include "mem.h";
#include "drivers/video/screen.h";

#define MEMORY_SIZE 0x100000 // 1MB
static char memory_pool[MEMORY_SIZE];
static unsigned int mem_used = 0;

void kmalloc(unsigned int size) {
    if(mem_used + size > MEMORY_SIZE) {
        print_on_screen("[MEM] out of memory!\n");
        return 0;
    }

    void *ptr = &memory_pool[mem_used];
    mem_used += size;

    return ptr;
}

void kfree(void *ptr) {
    //заглушка
    (void)ptr;
}

void mem_init(void) {
    mem_used = 0;
    print_on_screen("[MEM] Memory manager initialized (1MB)\n")
}