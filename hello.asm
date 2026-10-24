
global _main
extern _puts

section .data
    message db "Hello, World!", 0

section .text
_main:
    push message
    call _puts
    add esp, 4
    xor eax, eax
    ret
