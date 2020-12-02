ARCH     = x86
COMPILER = gcc

ifeq ($(ARCH), x86)
	BOOTFILE = boot.x86.S
else ifeq ($(ARCH), RISC-V)
	BOOTFILE = boot.riscv.S
else ifeq ($(ARCH), ARM)
	BOOTFILE = boot.arm.S
else
	BOOTFILE = boot.$(ARCH).S
endif

output:
	@# Outputs the boot & kernel object
	@make locate
	@as --32 boot/asm/boot.x86.S -o bin/boot.o
	@gcc kernel/nut/nut.h -o bin/nut.o

locate:
	@# Locates the include/ folder in /usr/include
	@cp -R kernel/include/ /usr/include/nut

tests:
	@# Just builds the tests
	@gcc tests/hello.c -o bin/hello
	@gcc tests/nums.c -o bin/nums
	@gcc tests/input.c -o bin/input
	@gcc tests/abort.c -o bin/abort