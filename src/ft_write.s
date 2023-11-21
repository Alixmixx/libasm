section .text
extern __errno_location
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
	test rax, rax		;
	js _exit_error		; check if sign flag is set (RAX < 0)
	ret

_exit_error:
	neg rax								; negate return value
	mov rdi, rax						; save the value in RAX to RDI
	call __errno_location wrt ..plt		; call error function and save errno address in RAX
										;This part specifies the relocation type for the call instruction. In a Position Independent Executable (PIE) or shared library, addresses of functions are not known at compile time. They are resolved at runtime by the dynamic linker/loader
	mov [rax], rdi						; save the old RAX to errno
	mov rax, -1							; set return value to -1 if error
	ret


section .note.GNU-stack
