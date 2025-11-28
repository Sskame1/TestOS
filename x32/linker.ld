ENTRY(_start)

SECTIONS
{
    . = 0x00100000;

    .text : {
        *(.text)
    }

    .data : {
        *(.data)
    }

    .bss : {
        *(.bss)
    }

    .multiboot_header : {
        *(.multiboot_header)
    }
}