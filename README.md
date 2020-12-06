# The nut kernel
Nut is a simple small kernel to make powerfull operative systems. Nut is made in C/C++, ASM, Makefile, NutScript and YACC & LEX for the NutScript interpreter. Nut has got many different modules, from I/O to FAT32 file system implementation.

### Getting nut
If you want to get the nut kernel, you have 2 options, get the built kernel in the [releases directory](https://github.com/HdbSoft/nut/releases) as a *.zip* file or build it by yourself. You can also get pre-compiled binaries from our [nut bins repository](https://github.com/HdbSoft/nut-bins).

If you want to build nut from source code, you first need to clone the repository into your machine:
```bash
$ git clone https://github.com/HdbSoft/nut.git nut
$ cd nut/
```

#### Building nut
If you don't want to build nut by using cross-compiling, you just need to use run this command replacing YOUR-ARCH by your architecture:
```bash
$ make ARCH=YOUR-ARCHITECTURE
```
by default, nut Makefile uses **x86** as target architecture.

###### Available architectures list
- **x86**
- **ARM**
- **ARM32**
- **RISC-V**
- **6502**
- **raspberrypiA-B-Zero**
- **raspberrypi2**
- **raspberrypi3-4**

You can also configure your compiler by replacing CC by your compiler's name (by default nut uses clang):
```bash
$ make CC=gcc
```

When you finish compiling, your binaries will be in the bin directory. If you want to build the complete nut environment (boot files, kernel, boot scripts and more...) you can run this command instead:
```bash
$ make release
```

you will see a new directory called release, there will be your binaries, and also a *.zip* file called *nut.YOUR-ARCH.zip*, there will be the nut environment.

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