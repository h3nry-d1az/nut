ARCH     = x86
COMPILER = gcc

ifeq ($(ARCH), x86)
	BOOTFILE := boot.x86.S
else ifeq ($(ARCH), RISC-V)
	BOOTFILE := boot.riscv.S
else ifeq ($(ARCH), ARM)
	BOOTFILE := boot.arm.S
else
	BOOTFILE := boot.$(ARCH).S
endif

output:
	@# Outputs the boot & kernel object
	@make locate
	@as --32 boot/asm/$(BOOTFILE) -o bin/boot.o
	@$(COMPILER) kernel/nut/nut.h -o bin/nut.o

locate:
	@# Locates the include/ folder in /usr/include
	@cp -R kernel/include/ /usr/include/nut

tests:
	@# Just builds the tests
	@$(COMPILER) tests/hello.c -o bin/hello
	@$(COMPILER) tests/nums.c -o bin/nums
	@$(COMPILER) tests/input.c -o bin/input
	@$(COMPILER) tests/abort.c -o bin/abort