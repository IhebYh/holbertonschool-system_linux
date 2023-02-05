BITS 64

	global asm_strstr	; Export our 'asm_strstr' function

	section .text

	; size_t asm_strstr(const char *str);
	; write a copycat of the function strlen

asm_strstr:

	push rbp		; setup
	mov rbp, rsp		; Those two lines are equivalent to 'enter'

while:
	mov rax, 0h
	push rdi
	push rsi
	jmp _strstr
_strstr_return:
	pop rsi
	pop rdi
	test rax, rax
	jnz end
	inc rdi
	cmp BYTE [rdi], 0h
	jz end
	jmp while

	end:
	mov rsp, rbp
	pop rbp
	ret

_strstr:
	push rbp,
	mov rbp, rsp

	push rdi
	mov rax, 0h

_strstr_while:
	movzx edx, byte [rdi]
	movzx ecx, byte [rsi]
	test cl, cl
	jz _strstr_found
	cmp dl, cl
	after:
	jnz _strstr_not_found
	inc rdi
	inc rsi
	jmp _strstr_while

_strstr_found:
	pop rax
	jmp _strstr_end
_strstr_not_found:
	pop rax
	mov rax, 0h
_strstr_end:
	mov rsp, rbp
	pop rbp
jmp _strstr_return