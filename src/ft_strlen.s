section .text
	global ft_strlen
	
ft_strlen:
	push rcx                     ; save rcx value
	xor rcx, rcx                 ; clear rcx (counter reg)
	
ft_strlen_loop:
	cmp BYTE [rdi], 0            ; compare byte at rdi to '\0'
	jz ft_strlen_exit           ; if true, go to exit
	
	inc rcx                      ; increase counter
	inc rdi                      ; increase pointer
	jmp ft_strlen_loop          ; loop back
	
ft_strlen_exit:
	mov rax, rcx                 ; put counter in rax
	pop rcx                      ; restore rcx
	ret

section .note.GNU-stack