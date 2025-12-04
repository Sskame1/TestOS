#ifndef MEM_H
#define MEM_H

void mem_init(void);
void kmalloc(unsigned int size);
void kfree(void *ptr);

#endif