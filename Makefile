output:
	@as --32 boot/boot.S -o bin/boot
	@gcc kernel/nut.h -o bin/nut

assembly:
	@gcc -S kernel/nut.h