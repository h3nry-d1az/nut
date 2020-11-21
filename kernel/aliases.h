#ifndef GINGER_ALIASES_H
#define GINGER_ALIASES_H

#define LOOP while (TRUE)

#define ptread(port)  __read_port(port)
#define ptwrite(port) __print_port(port)

#define charin __kernel_input()
#define input  __keyboard_input()

#define newline  __new_line()
#define putc(ch) __char_log(ch, __def_fore_color, __def_back_color)
#define puts(st) __string_log(st, __def_fore_color, __def_back_color)
#define puti(nu) __integer_log(nu, __def_fore_color, __def_back_color)
#define clear    __clear(__def_fore_color, __def_back_color)

#endif
//ginger function aliases