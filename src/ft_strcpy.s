section .text
global ft_strcpy

; Copy a C-style NUL-terminated string into another C-string
; 
; Inputs:   RDI = address of beginning of the destination string
; Outputs:  RSI = address of beginning of the source string
; Clobbers: RBX, flags	

ft_strcpy:
    mov  rax, rdi  ; dst
    mov  rbx, rsi  ; src

_loop:
    mov  al, [rsi]  ; load the byte from src in the al reg (rax's lower 8 bits)
    mov  [rdi], al  ; copy the byte from al to dst
    inc  rdi
    inc  rsi
    cmp  BYTE [rsi], 0
    jne  _loop

_exit:
    mov BYTE [rdi], 0     ; null terminate dst
    ret

section .note.GNU-stack