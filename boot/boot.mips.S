.global start

.extern NutInit
.extern Main

.set noreorder

.set STACKSIZE, 0x1000

.section .text

start:
	la $sp, stack
	addiu $sp, STACKSIZE - 32
	jal NutInit
	jal Main
	nop
	b .
	nop

.section .bss
stack:
	.space STACKSIZE