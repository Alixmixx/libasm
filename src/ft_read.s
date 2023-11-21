section .text
extern __errno_location
global ft_read

; Read up to the given length in the designated file descriptor into the given buffer
;
; Inputs:   RDI = file descriptor
;           RSI = address of the buffer
;		   	RDX = length to read
; Outputs:  EAX = number of bytes read or -1 on error
; Clobbers: RCX

ft_read:
	xor rax, rax
	syscall
	test rax, rax
	js _exit_error		; check if rax is negative
	ret

_exit_error:
	neg rax							; negate rax to get the error code
	mov rdi, rax					; move the error code to rdi
	call __errno_location wrt ..plt	; call __errno_location to get the errno address in rax
	mov [rax], rdi					; move the error code to the errno address
	mov rax, -1						; move -1 to rax
	ret

section .note.GNU-stack
