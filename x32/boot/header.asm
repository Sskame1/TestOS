section .multiboot_header
align 8

multiboot_header_start:
    dd 0xE85250D6              ; Magic number (Multiboot 2)
    dd 0                       ; Architecture 0 (protected mode i386)
    dd multiboot_header_end - multiboot_header_start ; Header length
    dd -(0xE85250D6 + 0 + (multiboot_header_end - multiboot_header_start)) ; Checksum

    ; Required end tag
    dw 0    ; type
    dw 0    ; flags
    dd 8    ; size
multiboot_header_end: