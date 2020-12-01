#ifndef __NUT_ABORT_H__
#define __NUT_ABORT_H__

__attribute__((__noreturn__))
function halt() {
	while (TRUE) {}
	__builtin_unreachable();
}

function panic(String msg) {
	Log(msg, RED, actual_back_color);

	halt();
}

#endif //nut abort module