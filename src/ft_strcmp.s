section .text
global ft_strcmp

; Compares two C-style NUL-terminated strings and return the difference of the first two differing bytes
;
; Inputs:   RDI = address of beginning of first string
;           RSI = address of beginning of second string
; Outputs:  EAX = difference of the first two differing bytes
; Clobbers: RCX, flags

ft_strcmp:
    xor rcx, rcx            ;set counter to 0

_loop:
    mov al, [rdi + rcx]     ; rdi = s1   move to al (8bit lower part of rdx)
    mov bl, [rsi + rcx]     ; rsi = s2   move to bl (8bit higher part of rdx)
    inc rcx                 ; increase counter
    test al, al             ; check if al is 0
    jz _exit                ; if al is 0, jump to exit
    cmp al, bl              ; compare al and bl
    je _loop                ; if equal loop again

_exit:
    movzx	rax, al			; movzx add extension with 0 to dest
	movzx	r8, bl          ; to convert to 64bit before sub
	sub		rax, r8			; rax = rax - r8
	ret

section .note.GNU-stack