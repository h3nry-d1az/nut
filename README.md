# The nut kernel
Nut is a simple small kernel to make powerfull operative systems. Nut is made in C/C++, ASM, Makefile, NutScript and YACC & LEX for the NutScript interpreter. Nut has got many different modules, from I/O to FAT32 file system implementation.


### Getting nut
If you want to get the nut kernel, you have 2 options, get the built kernel in the [releases directory](https://github.com/HdbSoft/nut/releases) as a *.zip* file or build it by yourself.

###### Building nut
The first thing you need to do is to clone the repository in your local machine:
```bash
$ git clone https://github.com/HdbSoft/nut.git nut
$ cd nut/
```

then, use the makefile to build it:
```bash
$ make
```

you can also configure your compiler and architecture:
```bash
$ make ARCH=YOUR-ARCHITECTURE COMPILER=YOUR-COMPILER
```

by default nut Makefile uses **x86** as target architecture and **gcc** as compiler.


Your binaries will be in the bin directory. If you want to build the complete nut environment (boot files, kernel, boot scripts and more...) you can run this command instead:
```bash
$ make release
```

you will see a new directory called release, there will be your binaries, and also a *.zip* file called *nut.YOUR-ARCH.zip*, there will be the nut environment.


### Contributing
If you want to contribute and you are not a member of HdbSoft, you just need to fork this repository and make your changes there, then make a pull request and we will see it.

### nut file tree
- **kernel/nut/nut.h:** The nut kernel header
- **kernel/nut/abort.h:** Kernel abort module
- **kernel/nut/functions.h:** Function prototypes
- **kernel/nut/io.h:** I/O functions
- **kernel/include/keys.h:** Keyboard keys ports module
- **kernel/include/types.h:** Nut data types module
- **kernel/include/ui.h:** UI module
- **kernel/include/utils.h:** Nut utilities module
- **kernel/nut/vga.h:** VGA module
- **kernel/nut/network.h:** Network module
- **kernel/nut/log.h:** Console log module
- **kernel/nut/files.h:** File module
- **kernel/nut/error.h:** Error module
- **kernel/include/py.h:** Python script module
- **kernel/script/parser.y:** NutScript parser
- **kernel/script/scanner.l:** NutScript scanner
- **boot/init.h:** nut init file
- **boot/asm/boot.x86.S:** nut x86 boot file
- **boot/asm/boot.arm.S:** nut arm boot file
- **boot/asm/boot.riscv.S:** nut RISC-V boot file
- **boot/asm/grub.cfg:** Grub configuration file
- **boot/asm/linker.ld:** nut linker
- **boot/ns/initialize.nut:** nut initializer script
- **boot/ns/logout.nut:** nut star script script
- **tests/hello.c:** Hello world test
- **tests/nums.c:** Number printing test
- **tests/input.c:** Input test
- **tests/abort.c:** Abort test


### [MIT license](LICENSE.md)

###### Copyright (c) 2020 HdbSoft

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

<br>
<br>
<br>

I hope you like the nut kernel.