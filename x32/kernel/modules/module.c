#include "module.h"
#include "drivers/video/screen.h"

static Module modules[MAX_MODULE];
static int module_count = 0;

void module_register(Module *module) {
    if (module_count >= MAX_MODULE) return;

     for (int i = 0; i < MODULE_MAX_LEN; i++) {
        modules[module_count].name[i] = module->name[i];
        if (module->name[i] == '\0') break;
    }
    modules[module_count].type = module->type;
    modules[module_count].init = module->init;
    modules[module_count].deinit = module->deinit;
    modules[module_count].status = 0;

    module_count++;
    
    // вывод инфы о модуле
    print_on_screen("[MODULE] Registered: ");
    print_on_screen(module->name);
    print_on_screen("\n");
}

int module_load(const char* name) {
    for (int i = 0; i < module_count; i++) {
        int j = 0;
        while (name[j] != '\0' && modules[i].name[j] != '\0') {
            if (name[j] != modules[i].name[j]) break;
            j++;
        }
        
        if (name[j] == '\0' && modules[i].name[j] == '\0') {
            if (modules[i].init && modules[i].status == 0) {
                modules[i].init();
                modules[i].status = 1;
                return 0;
            }
        }
    }
    
    print_on_screen("[ERROR] Module not found: ");
    print_on_screen(name);
    print_on_screen("\n");
    return -1;
}

void module_list(void) {
    print_on_screen("\n=== Loaded Modules ===\n");
    for(int i = 0; i < module_count; i++) {
        print_on_screen(" ");
        print_on_screen(modules[i].name);
        print_on_screen(" - ");

        switch(modules[i].status) {
            case 0: print_on_screen("REGISTERED\n"); break;
            case 1: print_on_screen("LOADED\n"); break;
            case 2: print_on_screen("ERROR\n"); break;
            default: print_on_screen("UNKNOWN\n");
        }
    }
}