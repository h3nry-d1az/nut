ARCH     = x86
COMPILER = gcc
VERSION  = 0.2.0

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

nutscript:
	@bison -d kernel/script/parser.y -o kernel/script/y.tab.c
	@flex -o kernel/script/lex.yy.c kernel/script/scanner.l

tests:
	@$(COMPILER) tests/hello.c bin/nut.o -o bin/hello
	@$(COMPILER) tests/nums.c bin/nut.o -o bin/nums
	@$(COMPILER) tests/input.c bin/nut.o -o bin/input
	@$(COMPILER) tests/abort.c bin/nut.o -o bin/abort

release:
	@make ARCH=$(ARCH)
	@mkdir release
	@mkdir release/ns
	@cp bin/nut.o release/
	@cp bin/boot.o release/
	@cp -r boot/ns release/
	@cp boot/asm/grub.cfg release/
	@cp boot/asm/linker.ld release/
	@zip -r nut.$(ARCH).zip release/