#include "module.h"
#include "drivers/video/screen.h"

static Module modules[MAX_MODULE];
static int module_count = 0;

void module_register(Module *module) {
    if (module_count >= MAX_MODULE) return;

    modules[module_count] = *module;
    module_count++;

    // вывод инфы о модуле
    print_on_screen("[MODULE] Registered: ");
    print_on_screen(module->name);
    print_on_screen("\n");
}

int module_load(const char *name) {
    for(int i = 0; i < module_count; i++) {
        int m = 1;
        for(int j = 0; name[j] != '\0'; j++) {
            if (modules[i].name[j] != name[j]) {
                m = 0;
                break;
            }
        }

        if(m && modules[i].init) {
            modules[i].init();
            modules[i].status = 1;

            print_on_screen("[MODULE] Loaded: ");
            print_on_screen(name);
            print_on_screen("\n");
            return 0;
        }
    }

    print_on_screen("[MODULE] Not found: ");
    print_on_screen(name);
    print_on_screen("\n");
    return -1;
}

void module_list(void) {
    print_on_screen("\n=== Loaded Modules ===\n");
    for(int i = 0; i < module_count; i++) {
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