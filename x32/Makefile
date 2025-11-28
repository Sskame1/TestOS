# переменные
ISO_NAME = testos.iso

# компиляторы и утилиты
CC = gcc
ASM = nasm
LD = ld
QEMU = qemu-system-x86_64

# флаги
CFLAGS = -ffreestanding -fno-builtin -fno-stack-protector -nostdlib -m64 -Ikernel
ASMFLAGS = -f elf64
LDFLAGS = -m elf_x86_64 -T linker.ld -nostdlib

# файлы
SOURCES_C = $(wildcard kernel/*.c)
SOURCES_ASM = $(wildcard boot/*.asm)
OBJECTS_C = $(SOURCES_C:.c=.o)
OBJECTS_ASM = $(SOURCES_ASM:.asm=.o)
OBJECTS = $(OBJECTS_C) $(OBJECTS_ASM)

# цели
all: $(ISO_NAME)

# компиляция C файлов
kernel/%.o: kernel/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# компиляция ASM файлов
boot/%.o: boot/%.asm
	$(ASM) $(ASMFLAGS) $< -o $@

# линковка
kernel.bin: $(OBJECTS)
	$(LD) $(LDFLAGS) -o $@ $^

# создание загрузочного образа
$(ISO_NAME): kernel.bin
	mkdir -p build/boot/grub
	cp grub/grub.cfg build/boot/grub/
	cp kernel.bin build/boot/
	grub-mkrescue -o $(ISO_NAME) build/

# запуск в QEMU
run: $(ISO_NAME)
	$(QEMU) -cdrom $(ISO_NAME)

# очистка
clean:
	rm -f *.o *.bin *.iso
	rm -rf build
	rm -f boot/*.o kernel/*.o

.PHONY: all run clean