section .text
global ft_strdup

; Allocate a new string and copy the contents of the given string into it.
;
; Inputs:   RDI = address of string

; Outputs:  EAX = address of new string
; Clobbers: RCX

ft_strdup:
	
	mov rdi, len
	call _malloc


section .note.GNU-stack
