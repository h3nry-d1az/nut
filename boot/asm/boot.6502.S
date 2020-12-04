MAGIC: 0x1BADB002
FLAGS: 0
CHECKSUM: -(MAGIC + FLAGS)


_start:
	jmp NutInit
	jmp Main

NutInit:
.export NutInit

Main:
.export Main


loop:
	nop
	jmp loop
