BITS 64

	global asm_strchr

	section .text

	
asm_strchr:

	push rbp
	mov rbp, rsp		

	mov rax, 0h

while:
	mov al, BYTE [rdi]
	cmp BYTE [rdi], sil
	jz found
	cmp BYTE [rdi], 0h
	jz retur
	inc rdi
	jmp while

found:
	mov rax, rdi

retur:

	mov rsp, rbp		
	pop rbp			

	ret