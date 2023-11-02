section .data
	errno_location db 0

section .text
global ft_write

; Write a string to the designated file descriptor of the given length
;
; Inputs:   RDI = file descriptor
;           RSI = address of string
;		   	RDX = characters to write in size_t
; Outputs:  EAX = length of string written or -1 on error
; Clobbers: RCX


ft_write:
	mov rax, 1			; syscall number for write
	syscall				; call
	jc _exit_error		; check if carry flag is set (RAX < 0)
	ret

_exit_error:
	neg rax					; negate return value
	mov rdi, rax			; save the value in RAX to RDI
	call errno_location		; call error function and save errno address in RAX
	mov [rax], rdi			; save the old RAX to errno
	mov rax, -1				; set return value to -1 if error
	ret

section .note.GNU-stack
