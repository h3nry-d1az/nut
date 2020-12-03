MAGIC: 0x1BADB002
FLAGS: 0
CHECKSUM: -(MAGIC + FLAGS)


.section .multiboot

stack_bottom:
.skip 1024

stack_top:
.section .text


_start:
	call NutInit
	call main

loop:
	mov r0, r0 #NOP instruction in ARM
	jmp loop