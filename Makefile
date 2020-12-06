ARCH        = x86
CC          = clang
ASSEMBLER   = as --32
INCLUDE-DIR = /usr/include
c2asm       = clang -S

ifeq ($(ARCH), x86)
	BOOTFILE := boot.x86.S
else ifeq ($(ARCH), RISC-V)
	BOOTFILE := boot.riscv.S
else ifeq ($(ARCH), ARM)
	BOOTFILE := boot.arm.S
else ifeq ($(ARCH), ARM32)
	BOOTFILE := boot.arm32.S
else ifeq ($(ARCH), 6502)
	BOOTFILE := boot.6502.S
	CC     = cc65
	c2asm := cc65
else ifeq ($(ARCH), raspberrypiA-B-Zero)
	BOOTFILE := raspberrypi/boot.abzero.S
else ifeq ($(ARCH), raspberrypi2)
	BOOTFILE := raspberrypi/boot.2.S
else ifeq ($(ARCH), raspberrypi3-4)
	BOOTFILE := raspberrypi/boot.34.S
else ifeq ($(ARCH), C)
	BOOTFILE := boot.h
	ASSEMBLER := $(CC)
else
	BOOTFILE := boot.$(ARCH).S
endif

output:
	@# Outputs the boot & kernel object
	@make locate INCLUDE-DIR=$(INCLUDE-DIR)
	@$(ASSEMBLER) boot/asm/$(BOOTFILE) -o bin/boot.o
	@$(CC) kernel/nut/nut.h -o bin/nut.o

locate:
	@# Locates the include/ folder in INCLUDE-DIR
	@cp -R kernel/include/ $(INCLUDE-DIR)/nut

nutscript:
	@bison -d kernel/script/parser.y -o kernel/script/y.tab.c
	@flex -o kernel/script/lex.yy.c kernel/script/scanner.l

tests:
	@$(CC) tests/hello.c bin/nut.o -o bin/hello
	@$(CC) tests/nums.c bin/nut.o -o bin/nums
	@$(CC) tests/input.c bin/nut.o -o bin/input
	@$(CC) tests/abort.c bin/nut.o -o bin/abort
	@$(CC) tests/image.c bin/nut.o -o bin/image

release:
	@make ARCH=$(ARCH) COMPILER=$(CC)
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