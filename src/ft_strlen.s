section .text
	global ft_strlen
	
ft_strlen:
	push rcx                     ; save rcx value
	xor rcx, rcx                 ; clear rcx (counter reg)
	
loop:
	cmp BYTE [rdi], 0            ; compare byte at rdi to '\0'
	jz exit         		     ; if true, go to exit
	
	inc rcx                      ; increase counter
	inc rdi                      ; increase pointer
	jmp loop          			 ; loop back
	
exit:
	mov rax, rcx                 ; put counter in rax
	pop rcx                      ; restore rcx
	ret

section .note.GNU-stack