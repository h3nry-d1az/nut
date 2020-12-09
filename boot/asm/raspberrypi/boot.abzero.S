.section ".text.boot"


.globl _start
	.org 0x8000

_start:
	// Setup the stack.
	mov sp, #0x8000
 
	// Clear out bss.
	ldr r4, =__bss_start
	ldr r9, =__bss_end
	mov r5, #0
	mov r6, #0
	mov r7, #0
	mov r8, #0
	b       2f
 
1:
	stmia r4!, {r5-r8}

2:
	cmp r4, r9
	blo 1b
 
 	ldr r3, =NutInit
 	blx r3
 
	ldr r3, =Main
	blx r3


//halt
halt:
	wfe
	b halt