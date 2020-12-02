output:
	@# Outputs the boot & kernel assembly
	@as --32 boot/asm/boot.x86.S -o bin/boot.o
	@gcc kernel/nut/nut.h -o bin/nut.o

test:
	@# Just builds the tests
	@gcc tests/hello.c -o bin/hello
	@gcc tests/nums.c -o bin/nums
	@gcc tests/input.c -o bin/input