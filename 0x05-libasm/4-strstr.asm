BITS 64
        .global asm_strstr
        section .text

asm_strstr:
        push rbp
        mov rbp, rsp
        push rcx
  	    xor rax, rax

while:
        mov al, BYTE [rdi]
        mov cl, BYTE [rsi]
	    cmp al, cl
	    jz found
	    cmp BYTE [rdi], 0
	    jz end
        inc al
        jmp while
found:
        inc al
        inc cl
        cmp BYTE [rsi], 0
        cmp al, cl
        jne while
