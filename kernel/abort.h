#ifndef __NUT_ABORT_H__
#define __NUT_ABORT_H__

__attribute__((__noreturn__))
function abort(String message) {
	strout (
		"Nut kernel v0.1.2 says:\n"
		"ABORT!!: "
	);

	strout(message);

	while (TRUE) {}
	__builtin_unreachable();
}

#endif //nut abort module