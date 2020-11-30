#ifndef NUT_ABORT_H
#define NUT_ABORT_H

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