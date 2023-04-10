The nut kernel
==============
Nut is a simple small kernel to make powerfull operative systems. Nut is made in C/C++, ASM, Makefile, NutScript and YACC & LEX for the NutScript interpreter. Nut has got many different modules, from I/O to FAT32 file system implementation.

### Getting nut
If you want to get the nut kernel, you have 2 options, get the built kernel in the [releases directory](https://github.com/h3nry-d1az/nut/releases) as a *.zip* file or build it by yourself.

If you want to build nut from source code, you first need to clone the repository into your machine:
```bash
$ git clone https://github.com/h3nry-d1az/nut.git nut
$ cd nut/
```

#### Building nut
If you don't want to build nut by using cross-compiling, you just need to use run this command replacing YOUR-ARCH by your architecture:
```bash
$ make ARCH=YOUR-ARCHITECTURE
```
by default, nut Makefile uses **x86** as target architecture.

> **NOTE:** if you haven't build nut before, you will need to make with the EXISTS-NUT-INCLUDE as no:\
> `$ make EXISTS-NUT-INCLUDE=no`
>
> If you haven't got the necessary tools to build nut, you can install them by running your OS's nut setup file:\
> `$ ./setup/setup.YOUR-OS.sh`

You can also cross-compile nut, by setting the CC variable by your cross compiler and the ASSEMBLER variable by your cross assembler. For example, if you want to cross-compile nut from x86 to ARM32, you can run this:
```bash
$ make "CC=arm-linux-gnueabihf-gcc" "ASSEMBLER=arm-none-eabi-gcc -mcpu=cortex-a7 -fpic -ffreestanding -c" ARCH=ARM32
```

or if you want to build nut for Sun SPARC, you can run this command:
```bash
$ make CC=sparc-elf-gcc ASSEMBLER=sparc-elf-as ARCH=SPARC
```

you can also build nut for MOS 6502 (by now is unstable):
```bash
$ make CC=cc65 ASSEMBLER=cl65 ARCH=6502
```

> **NOTE:** cross compilers are not included in nut's setup scripts, if you want to cross compile, you will need to get them by yourself.

You can just build the kernel or the bootfile by running the `kernel` or the `bootfile` recipe.


###### Available architectures list
- **x86**
- **ARM**
- **ARM32**
- **RISC-V**
- **6502**
- **raspberrypiA-B-Zero**
- **raspberrypi2**
- **raspberrypi3-4**
- **SPARC**
- **MIPS**
- **C**

You can also configure your compiler by replacing CC by your compiler's name (by default nut uses clang):
```bash
$ make CC=gcc
```

your output directory:
```bash
$ make OUTPUT=bin
```

your assembler:
```bash
$ make ASSEMBLER=as
```

and more...

When you finish compiling, your binaries will be in the bin directory. If you want to build the complete nut environment (boot files, kernel, boot scripts and more...) you can run this command instead:
```bash
$ make release
```

you will see a new directory called release, there will be your binaries, and also a *.zip* file called *nut.YOUR-ARCH.zip*, there will be the nut environment.

#### Nut documentation
At the moment, you can read the (incomplete) documentation of the nut kernel by going to the [following link](https://h3nry-d1az.github.io/nut/nut-docs.pdf).

In addition, you can also compile it yourself by running the `docs` recipe in the project Makefile, for which you can set the following parameters:
- The `LATEX` parameter contains the compiler to use for the recipe, the default is `pdflatex`.
- The `DOCS-OUTPUT-DIR` parameter contains the directory in which the .pdf file will be saved, the default is `.`.
- The `DOCS-OUTPUT-NAME` parameter contains the name that the aforementioned .pdf file will have, by default it is `nut-docs`.
- The `VERBOSE` parameter indicates whether `pdflatex` or the program in question should print text to the screen, by default it doesn't, ergo its value is `/dev/null` (because the text will be redirected there).

You can run the recipe with the following command:
```bash
$ make docs LATEX=compiler DOCS-OUTPUT-DIR=your-dir DOCS-OUTPUT-NAME=your-name VERBOSE=/dev/null
```

### Contributing
If you want to contribute and you are not a member of HdbSoft, you just need to fork this repository and make your changes there, then make a pull request and we will see it.


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