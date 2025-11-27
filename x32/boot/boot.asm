section .text
global _start
extern kernel

; Multiboot header
align 4
multiboot_header:
    dd 0x1BADB002              ; magic
    dd 0x00000003              ; flags
    dd -(0x1BADB002 + 0x00000003) ; checksum

_start:
    ; ставим стек
    mov esp, stack_space
    
    ; вызов функции ядра
    call kernel
    
    ; бесконечный цикл если ядро вернется
    cli
    hlt

section .bss
resb 8192
stack_space: