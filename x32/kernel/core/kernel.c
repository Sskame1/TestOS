#include "drivers/video/screen.h"
#include "modules/module.h"
#include "ipc/ipc.h"

// простенький планировщик - round-robin
typedef struct {
    int pid;
    int status;
    void *stack_pointer //0 - готов 1 - работает 2 - заблокирован
} Task;

static Task tasks[32];
static int current_task = 0;
static int task_count = 0;

void kernel_main() {
    clear_screen();

    while (1)
    {
        asm volatile ("hlt");
    }
    
}