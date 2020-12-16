_start:
	call NutInit
	call Main

loop:
	addi x0, x0, 0 #NOP instruction in RISC-V
	jal loop