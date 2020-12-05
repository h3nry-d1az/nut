ARCH        = x86
COMPILER    = clang
ASSEMBLER   = as --32
INCLUDE-DIR = /usr/include

ifeq ($(ARCH), x86)
	BOOTFILE := boot.x86.S
	c2asm := clang -S
else ifeq ($(ARCH), RISC-V)
	BOOTFILE := boot.riscv.S
	c2asm := clang -S
else ifeq ($(ARCH), ARM)
	BOOTFILE := boot.arm.S
	c2asm := clang -S
else ifeq ($(ARCH), 6502)
	BOOTFILE := boot.6502.S
	COMPILER = cc65
	c2asm := cc65
else ifeq ($(ARCH), C)
	BOOTFILE := boot.h
	ASSEMBLER := $(COMPILER)
	c2asm := clang -S
else
	BOOTFILE := boot.$(ARCH).S
	c2asm := clang -S
endif

output:
	@# Outputs the boot & kernel object
	@make locate INCLUDE-DIR=$(INCLUDE-DIR)
	@$(ASSEMBLER) boot/asm/$(BOOTFILE) -o bin/boot.o
	@$(COMPILER) kernel/nut/nut.h -o bin/nut.o

locate:
	@# Locates the include/ folder in INCLUDE-DIR
	@cp -R kernel/include/ $(INCLUDE-DIR)/nut

nutscript:
	@bison -d kernel/script/parser.y -o kernel/script/y.tab.c
	@flex -o kernel/script/lex.yy.c kernel/script/scanner.l

tests:
	@$(COMPILER) tests/hello.c bin/nut.o -o bin/hello
	@$(COMPILER) tests/nums.c bin/nut.o -o bin/nums
	@$(COMPILER) tests/input.c bin/nut.o -o bin/input
	@$(COMPILER) tests/abort.c bin/nut.o -o bin/abort
	@$(COMPILER) tests/image.c bin/nut.o -o bin/image

release:
	@make ARCH=$(ARCH) COMPILER=$(COMPILER)
	@mkdir release
	@mkdir release/ns
	@cp bin/nut.o release/
	@cp bin/boot.o release/
	@cp -r boot/ns release/
	@cp boot/asm/grub.cfg release/
	@cp boot/asm/linker.ld release/
	@zip -r nut.$(ARCH).zip release/

clean:
	@rm -r release/
	@rm nut.$(ARCH).zip
	@rm bin/nut.o
	@rm bin/boot.o

C2ASM:
	@make locate INCLUDE-DIR=$(INCLUDE-DIR)
	@$(c2asm) kernel/nut/nut.h -o nut.S

config:
	@vim boot/asm/grub.cfg