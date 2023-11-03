section .text
global ft_strcpy

; Copy a C-style NUL-terminated string into another C-string
; 
; Inputs:   RDI = address of beginning of the destination string
;           RSI = address of beginning of the source string
;
; Outputs:  RAX = address of beginning of the destination string
; Clobbers: RBX, flags	

ft_strcpy:
    mov  rax, rdi  ; dst
    xor r8b, r8b   ; r8b = 0
    
_loop:
    mov  r8b, [rsi]  ; load the byte from src in the r8b reg (r8's lower 8 bits)
    mov  [rdi], r8b  ; copy the byte from r8b to dst
    inc  rdi
    inc  rsi
    cmp  BYTE [rsi], 0
    jne  _loop

_exit:
    mov BYTE [rdi], 0     ; null terminate dst
    ret

section .note.GNU-stack
