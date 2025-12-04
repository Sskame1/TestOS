#include "../drivers/video/screen.h"
#include "../modules/module.h"
#include "../ipc/ipc.h"
#include "mem.h"

// простенький планировщик - round-robin
typedef struct {
    int pid;
    int status;
    void *stack_pointer; //0 - готов 1 - работает 2 - заблокирован
} Task;

static Task tasks[32];
static int current_task = 0;
static int task_count = 0;

void kernel_main() {
    clear_screen();
    print_on_screen("=== Microkernel Starting ===\n\n");

    // инициализация подсистем
    print_on_screen("[INIT] Core systems...\n");
    ipc_init();

    // регистрируем модули
    print_on_screen("[INIT] Registering modules...\n");
    screen_module_init();

    // загружаем модули
    print_on_screen("[INIT] Loading modules...\n");
    module_load("video_screen");

    //создаем системные процессы (пока что заглушка)
    print_on_screen("[INIT] Loading modules...\n");

    module_list();

    print_on_screen("[INIT] Memory init...\n");
    mem_init();

    print_on_screen("\n>>>");

    // демо ipd (заглушка)
    print_on_screen("\n[DEMO] IPC system ready\n");

    while (1)
    {
        asm volatile ("hlt");
    }
    
}