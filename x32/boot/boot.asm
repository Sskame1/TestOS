section .text
bits 32
global _start
extern kernel_main

_start:
    ; проверка multiboot
    cmp eax, 0x36d76289        ; Multiboot2 magic value
    jne .no_multiboot

    ; установка стека
    mov esp, stack_space

    ; инициализация сегментов данных
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    ; вызов ядра
    call kernel_main
    
    ; бесконечный цикл если ядро вернется
    cli
.halt:
    hlt
    jmp .halt

.no_multiboot:
    mov dword [0xB8000], 0x4F4B4F4E  ; вывод "NO" на экран красненький
    cli
    hlt

section .bss
align 16
stack_bottom:
resb 16384  ; 16 KB стека
stack_space: