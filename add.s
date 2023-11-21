section .text
global add

; Add one
;
; Inputs:   RAX = int
; Outputs:  RAX = 
; Clobbers: RCX, flags

add:
    inc rax;