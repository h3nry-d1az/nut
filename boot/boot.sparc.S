.section .text
.align 16

.global _start


_start:
	call 1f
	mov %o7, %l0
	
	call NutInit
	call Main

1:
	nop
	jmp 1