#ifndef __NUT_ABORT_H__
#define __NUT_ABORT_H__

__attribute__((__noreturn__))
function abort(String msg) {
	Log(msg, RED, actual_back_color);

	while (TRUE) {}
	__builtin_unreachable();
}

#endif //nut abort module