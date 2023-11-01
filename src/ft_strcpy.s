section .text
global ft_strcpy

ft_strcpy:
    push rax
    push rbx
    mov  rax, rdi  ; dst
    mov  rbx, rsi  ; src

loop:
    mov  al, [rsi]  ; load the byte from src in the al reg (rax's lower 8 bits)
    mov  [rdi], al  ; copy the byte from al to dst
    inc  rdi
    inc  rsi
    cmp  BYTE [rsi], 0
    jne  loop

exit:
    mov BYTE [rdi], 0     ; null terminate dst
    pop rax
    pop rbx
    ret

section .note.GNU-stack