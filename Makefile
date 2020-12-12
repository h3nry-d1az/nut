ARCH               = x86
CC                 = clang
OUTPUT             = bin
NUTOBJ             = nut.so
BOOTOBJ            = boot.o
ASSEMBLER          = as --32
INCLUDE-DIR        = /usr/include
c2asm              = clang -S
CROSS-COMPILE      = no
EXISTS-NUT-INCLUDE = yes


ifeq ($(EXISTS-NUT-INCLUDE), no)
	ACTION := mkdir $(INCLUDE-DIR)/nut
endif
# Make the /usr/include/nut directory


ifeq ($(CROSS-COMPILE), yes)
	ASSEMBLER = $(CC)
endif
# Cross-compile support


ifeq ($(ARCH), x86)
	BOOTFILE := boot.x86.S
	ARCHFILE := x86.h
else ifeq ($(ARCH), RISC-V)
	BOOTFILE := boot.riscv.S
	ARCHFILE := RISC-V.h
else ifeq ($(ARCH), ARM)
	BOOTFILE := boot.arm.S
	ARCHFILE := ARM.h
else ifeq ($(ARCH), ARM32)
	BOOTFILE := boot.arm32.S
	ARCHFILE := ARM32.h
else ifeq ($(ARCH), 6502)
	BOOTFILE := boot.6502.S
	CC        = cc65
	ASSEMBLER = cl65
	c2asm := cc65
	ARCHFILE := 6502.h
else ifeq ($(ARCH), raspberrypiA-B-Zero)
	BOOTFILE := raspberrypi/boot.abzero.S
	ARCHFILE := raspberrypiA-B-Zero.h
else ifeq ($(ARCH), raspberrypi2)
	BOOTFILE := raspberrypi/boot.2.S
	ARCHFILE := raspberrypi2.h
else ifeq ($(ARCH), raspberrypi3-4)
	BOOTFILE := raspberrypi/boot.34.S
	ARCHFILE := raspberrypi3-4.h
else ifeq ($(ARCH), C)
	BOOTFILE := boot.h
	ASSEMBLER := $(CC)
	ARCHFILE := C.h
else
	BOOTFILE := boot.$(ARCH).S
	ARCHFILE := $(ARCH).h
endif
# Architecture configuration

output:
	@# Outputs the boot & kernel object
	@make bootfile ASSEMBLER=$(ASSEMBLER) BOOTFILE=$(BOOTFILE) OUTPUT=$(OUTPUT) BOOTOBJ=$(BOOTOBJ)
	@make --always-make kernel INCLUDE-DIR=$(INCLUDE-DIR) CC=$(CC) ARCHFILE=$(ARCHFILE) OUTPUT=$(OUTPUT) NUTOBJ=$(NUTOBJ)

kernel:
	@make locate INCLUDE-DIR=$(INCLUDE-DIR)
	@make nutscript
	@$(CC) -c kernel/nut/nut.c -I kernel/arch/$(ARCHFILE) -o $(OUTPUT)/$(NUTOBJ)

bootfile:
	@$(ASSEMBLER) boot/$(BOOTFILE) -o $(OUTPUT)/$(BOOTOBJ)

locate:
	@# Locates the include/ folder in INCLUDE-DIR
	@$(ACTION)
	@cp -R kernel/include/* $(INCLUDE-DIR)/nut/

nutscript:
	@bison -d kernel/script/parser.y -o kernel/script/y.tab.c
	@flex -o kernel/script/lex.yy.c kernel/script/scanner.l

test:
	@make NUTOBJ=nut.so
	@$(CC) -c tests/hello.c -L$(OUTPUT) -o $(OUTPUT)/hello.out
	@$(CC) -c tests/nums.c -L$(OUTPUT) -o $(OUTPUT)/nums.out
	@$(CC) -c tests/input.c -L$(OUTPUT) -o $(OUTPUT)/input.out
	@$(CC) -c tests/abort.c -L$(OUTPUT) -o $(OUTPUT)/abort.out

release:
	@make ARCH=$(ARCH) COMPILER=$(CC)
	@mkdir release
	@cp bin/$(NUTOBJ) release/
	@cp bin/boot.o release/
	@cp boot/grub.cfg release/
	@cp boot/linker.ld release/
	@zip -r nut.$(ARCH).zip release/

clean:
	@rm -r release/
	@rm nut.$(ARCH).zip
	@rm $(OUTPUT)/$(NUTOBJ)
	@rm $(OUTPUT)/$(BOOTOBJ)

C2ASM:
	@make locate INCLUDE-DIR=$(INCLUDE-DIR)
	@$(c2asm) kernel/nut/nut.h -o nut.S

config:
	@vim boot/asm/grub.cfg