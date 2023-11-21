section .text
	global ft_strdup
	extern ft_strlen
	extern ft_strcpy
	extern malloc

; Allocate a new string and copy the contents of the given string into it.
;
; Inputs:   RDI = address of string
;
; Outputs:  EAX = address of new string
; Clobbers:

ft_strdup:
	mov r8, rdi		    ; save address of string
	call ft_strlen		; get len of string
	mov rdi, rax		; len of malloc
	inc rdi			    ; add 1 for null terminator
	call malloc	wrt ..plt		; pointer stored in rax
	mov rdi, rax		; address of destination
	mov rsi, r8		    ; address of source
	call ft_strcpy		; copy string
	ret

section .note.GNU-stack
