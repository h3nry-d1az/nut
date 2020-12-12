.segment	"RODATA"
_MAGIC:
	.word	$B002
_FLAGS:
	.word	$0000
_CHECKSUM:
	.word	$4FFE


.segment	"CODE"
.proc	__start: near


.segment	"CODE"
	call NutInit
	call Main

.endproc


.segment	"CODE"
.proc	_loop: near

.segment	"CODE"
	jmp _loop

.endproc