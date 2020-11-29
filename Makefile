output:
	@# Outputs the boot & kernel assembly
	@as --32 boot/boot.S -o bin/boot.o
	@gcc kernel/nut.h -o bin/nut.o

assembly:
	@# Outputs assembly code
	@gcc -S kernel/nut.h

test:
	@# Just builds the tests
	@gcc tests/hello.c -o bin/hello
	@gcc tests/nums.c -o bin/nums
	@gcc tests/input.c -o bin/input