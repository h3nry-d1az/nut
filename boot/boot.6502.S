	.setcpu		"6502"
	.smart		on
	.autoimport	on
	.case		on
	.debuginfo	off
	.importzp	sp, sreg, regsave, regbank
	.importzp	tmp1, tmp2, tmp3, tmp4, ptr1, ptr2, ptr3, ptr4
	.macpack	longbranch
	.export		MAGIC
	.export		FLAGS
	.export		CHECKSUM
	.import		NutInit
	.import		Main
	.export		_start
	.export		loop

.segment	"RODATA"

MAGIC:
	.word	$B002

FLAGS:
	.word	$0000

CHECKSUM:
	.word	$4FFE


.segment	"CODE"

.proc	_start: near

.segment	"CODE"

	ldy     #$00
	jsr     NutInit
	ldy     #$00
	jsr     Main
	rts

.endproc


.segment	"CODE"

.proc	loop: near

.segment	"CODE"

	jmp     L000B

L000B:	jmp L000B
	rts

.endproc