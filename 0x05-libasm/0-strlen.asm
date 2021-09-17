BITS 64
        global asm_strlen
        section .text
asm_strlen:
        push    rbp
        mov     rbp, rsp
        mov     QWORD [rbp-24], rdi
        mov     QWORD [rbp-8], 0
        jmp     .L2
.L3:
        add     QWORD [rbp-8], 1
.L2:
        mov     rax, QWORD [rbp-8]
        mov     rdx, QWORD [rbp-24]
        add     rax, rdx
        movzx   eax, BYTE [rax]
        test    al, al
        jne     .L3
        mov     rax, QWORD [rbp-8]
        pop     rbp
        ret
    