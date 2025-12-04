#ifndef MODULE_H
#define MODULE_H

#define MAX_MODULE 32
#define MODULE_MAX_LEN 32

// типы модулей
typedef enum {
    MODULE_DRIVER = 1,
    MODULE_SERVICE = 2,
} ModuleType;

// структура модуля
typedef struct {
    char name[MODULE_MAX_LEN];
    ModuleType type;
    void (*init)(void);
    void (*deinit)(void);
    int status; // 0 - не загружен, 1 - загружен, 2 - ошибка
} Module;

// api для регистрации модулей
void module_register(Module *module);
int module_load(const char *name);
void module_list(void);

#endif