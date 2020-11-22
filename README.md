# The nut kernel
Nut is a simple small kernel to make powerfull operative systems. Nut is totally made in C/C++ and ASM for example boot files. Nut has got a VGA I/O module, which you can use to print text into a screen.

### Getting nut
If you want to get the nut kernel, you have 2 options, get the built kernel in the [releases directory](https://github.com/HdbSoft/nut/releases) as a *.zip* file or build it by yourself.

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

<br>
<br>
<br>

I hope you like this repository, please give it a ⭐