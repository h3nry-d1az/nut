# The nut kernel
Nut is a simple small kernel to make powerfull operative systems. Nut is totally made in C/C++ and ASM for example boot files. Nut has got a VGA I/O module, which you can use to print text into a screen.


### Getting nut
If you want to get the nut kernel, you have 2 options, get the built kernel in the [releases directory](https://github.com/HdbSoft/nut/releases) as a *.zip* file or *.h* header or build it by yourself.

###### Building nut
The first thing you need to do is to clone the repository in your local machine:
```bash
$ git clone https://github.com/HdbSoft/nut.git nut
$ cd nut/
```

Then, use the makefile to build it:
```bash
$ make
```

Your binaries will be in the bin directory.


### nut files
- **kernel/nut.h:** The nut kernel header
- **kernel/io.h:** I/O functions
- **kernel/keys.h:** Keyboard keys ports module
- **kernel/types.h:** Nut data types module
- **kernel/ui.h:** UI module
- **kernel/utils.h:** Nut utilities module
- **kernel/vga.h:** VGA module
- **boot/boot.S:** Example bootfile
- **boot/grub.cfg:** Grub configuration file


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

I hope you like this repository, please give it a ⭐