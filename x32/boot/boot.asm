section .text
global _start
extern kernel

_start:
    ; установка стека
    mov esp, stack_space
    
    ; проверка multiboot
    cmp eax, 0x36d76289        ; Multiboot2 magic value
    jne .no_multiboot
    
    ; вызов ядра
    call kernel
    
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