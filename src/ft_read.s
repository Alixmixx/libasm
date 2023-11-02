section .text
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
	jc _exit_error
	ret

_exit_error:
	mov rax, -1
	ret


