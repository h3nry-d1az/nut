# CROSS COMPILATION TIPS FOR X86 USERS
# --------------------------------
# If you want to build nut for ARM (including raspberryPi and ARM 32)
# you can cross compile the nut kernel by using the arm-linux-gnueabihf-gcc
# compiler, and the arm-none-eabi-gcc assembler with the following flags:
#
# raspberryPi A, B, Zero:
# -mcpu=arm1176jzf-s -fpic -ffreestanding -c
#
# raspberryPi 2, ARM32:
# -mcpu=cortex-a7 -fpic -ffreestanding -c
#
# raspberryPi 3, 4, ARM64:
# In this case, arm-none-eabi-gcc is not a valid assembler, instead, you should
# use the following assembler with the following flags:
#
# aarch64-elf-as -c
#
#
# If you want to build nut for RISC-V, you can use the riscv64-linux-gnu-as assembler and the
# riscv64-linux-gnu-gcc compiler
#
#
# If you want to build nut for MOS 6502 (by now, nut has errors with this architecture),
# you should use the cc65 compiler and the cl65 assembler. For example:
#
# $ make CC=cc65 ASSEMBLER=cl65 ARCH=6502
#
#
# If you want to build nut for Sun SPARC, you can use the sparc-elf-as assembler and the
# sparc-elf-gcc compiler.
#
#
# If you want to build nut for MIPS, you can use the mipsel-elf-as assembler and the mipsel-elf-gcc
# compiler.

ARCH               = x86
CC                 = clang
OUTPUT             = bin
NUTOBJ             = nut.so
BOOTOBJ            = boot.o
ASSEMBLER          = as --32
INCLUDE-DIR        = /usr/include
C2ASM              = clang -S
EXISTS-NUT-INCLUDE = yes


ifeq ($(EXISTS-NUT-INCLUDE), no)
	ACTION := mkdir $(INCLUDE-DIR)/nut
endif
# Make the /usr/include/nut directory


ifeq ($(ARCH), x86)
	BOOTFILE := boot.x86.S
	ARCHFILE := x86.h
	CFLAGS   := -c
else ifeq ($(ARCH), RISC-V)
	BOOTFILE := boot.riscv.S
	ARCHFILE := RISC-V.h
	CFLAGS   := -c
else ifeq ($(ARCH), ARM)
	BOOTFILE := boot.arm.S
	ARCHFILE := ARM.h
	CFLAGS   := -c
else ifeq ($(ARCH), ARM32)
	BOOTFILE := boot.arm32.S
	ARCHFILE := ARM32.h
	CFLAGS   := -c
else ifeq ($(ARCH), 6502)
	BOOTFILE := boot.6502.S -c
	ARCHFILE := 6502.h
else ifeq ($(ARCH), raspberrypiA-B-Zero)
	BOOTFILE := raspberrypi/boot.abzero.S
	ARCHFILE := raspberrypiA-B-Zero.h
	CFLAGS   := -c
else ifeq ($(ARCH), raspberrypi2)
	BOOTFILE := raspberrypi/boot.2.S
	ARCHFILE := raspberrypi2.h
	CFLAGS   := -c
else ifeq ($(ARCH), raspberrypi3-4)
	BOOTFILE := raspberrypi/boot.34.S
	ARCHFILE := raspberrypi3-4.h
	CFLAGS   := -c
else ifeq ($(ARCH), SPARC)
	BOOTFILE := boot.sparc.S
	ARCHFILE := SPARC.h
	CFLAGS   := -c
else ifeq ($(ARCH), MIPS)
	BOOTFILE := boot.mips.S
	ARCHFILE := MIPS.h
	CFLAGS   := -c
else ifeq ($(ARCH), C)
	BOOTFILE := boot.c -c
	ASSEMBLER := $(CC)
	ARCHFILE := C.h
	CFLAGS   := -c
else
	BOOTFILE := boot.$(ARCH).S
	ARCHFILE := $(ARCH).h
	CFLAGS   := -c
endif
# Architecture configuration

output:
	@# Outputs the boot & kernel object
	@make bootfile ASSEMBLER="$(ASSEMBLER)" BOOTFILE="$(BOOTFILE)" OUTPUT="$(OUTPUT)" BOOTOBJ="$(BOOTOBJ)"
	@make modules OBJCC="$(OBJCC)" OBJCFLAGS="$(OBJCFLAGS)" OUTPUT="$(OUTPUT)"
	@make --always-make kernel INCLUDE-DIR="$(INCLUDE-DIR)" CC="$(CC)" ARCHFILE="$(ARCHFILE)" OUTPUT="$(OUTPUT)" NUTOBJ="$(NUTOBJ)"

kernel:
	@make locate INCLUDE-DIR=$(INCLUDE-DIR)
	@make nutscript
	@$(CC) $(CFLAGS) kernel/nut/nut.c -I kernel/arch/$(ARCHFILE) -o $(OUTPUT)/$(NUTOBJ)

bootfile:
	@$(ASSEMBLER) boot/$(BOOTFILE) -o $(OUTPUT)/$(BOOTOBJ)

modules:
	@$(CC) $(CFLAGS) kernel/modules/ui.c -o $(OUTPUT)/UI.o
	@$(CC) $(CFLAGS) kernel/modules/cursor.c -o $(OUTPUT)/cursor.o
	@$(CC) $(CFLAGS) kernel/modules/sound.c -o $(OUTPUT)/sound.o

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
	@make ARCH=$(ARCH) COMPILER="$(CC)" ASSEMBLER="$(ASSEMBLER)"
	@mkdir release
	@cp bin/$(NUTOBJ) release/
	@cp bin/boot.o release/
	@cp boot/grub.cfg release/
	@cp boot/linker.ld release/
	@zip -r nut.$(ARCH).zip release/

clean:
	@make rmbins
	@rm -r release/
	@rm nut.$(ARCH).zip

rmbins:
	@rm $(OUTPUT)/$(NUTOBJ)
	@rm $(OUTPUT)/$(BOOTOBJ)
	@rm $(OUTPUT)/UI.o
	@rm $(OUTPUT)/cursor.o
	@rm $(OUTPUT)/sound.o

c2asm:
	@make locate INCLUDE-DIR=$(INCLUDE-DIR)
	@$(C2ASM) kernel/nut/nut.h -o nut.S

config:
	@vim boot/asm/grub.cfg