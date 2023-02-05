BITS 64

	global asm_memcpy	; Export our 'asm_memcpy' function

	section .text

	; void *asm_memcpy(void *dest, const void *src, size_t n);
	; Write a copycat of the function memcpy

asm_memcpy:

	push rbp		; setup
	mov rbp, rsp		; Those two lines are equivalent to 'enter'

	push rdi
	mov rax, 0h

copy_while:
	test rdx, rdx
	jz retur
	dec rdx
	mov al, BYTE [rsi]
	mov BYTE [rdi], al
	inc rdi
	inc rsi
	jmp copy_while

retur:
	pop rax

	mov rsp, rbp		; Restore previous stack frame
	pop rbp			; Those two lines are equivalent to 'leave'

	ret			; Return from procedure ('pop rip')