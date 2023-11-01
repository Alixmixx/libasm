section .text
global ft_strcmp

ft_strcmp:
    push rbx
    xor rax, rax

loop:
    mov al, [rdi]
    mov bl, [rsi]
    cmp al, bl
    jne exit
    inc rdi
    inc rsi
    cmp al, 0
    jne loop

exit:
    sub al, bl
    pop rbx
    ret

section .note.GNU-stack