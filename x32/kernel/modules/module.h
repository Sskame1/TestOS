#ifndef MODULE_H
#define MODULE_H

#define MAX_MODULE 32
#define MODULE_MAX_LEN 32

// типы модулей
typedef enum {
    MODULE_DRIVER,
    MODULE_SERVICE,
    MODULE_FILESYSTEM,
    MODULE_NETWORK
} moduleType;

// структура модуля
typedef struct {
    char name[MODULE_MAX_LEN];
    moduleType type;
    void (*init)(void);
    void (*deinit)(void);
    int status; // 0 - не загружен, 1 - загружен, 2 - ошибка
} Module;

// api для регистрации модулей
void module_register(Module *module);
int module_load(const char *name);
int module_unload(const char *name);
void module_list(void);

#endif