section .text
	global ft_strlen

; Determines the length of a C-style NUL-terminated string.
; 
; Inputs:   RDI = address of beginning of string
; Outputs:  RAX = length of the string
; Clobbers: RCX, flags	
	
ft_strlen:
	xor rcx, rcx                 ; clear rcx (counter reg)
	
_loop:
	cmp BYTE [rdi], 0            ; compare byte at rdi to '\0'
	jz _exit         		     ; if true, go to _exit
	
	inc rcx                      ; increase counter
	inc rdi                      ; increase pointer
	jmp _loop          			 ; _loop back
	
_exit:
	mov rax, rcx                 ; put counter in rax
	ret

section .note.GNU-stack