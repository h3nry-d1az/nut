.arm
.text
.global _start


_start:
	call NutInit
	call Main

loop:
	nop
	bl loop