#ifndef __NUT_ERROR_H__
#define __NUT_ERROR_H__

typedef struct __NutError__ {
	String msg;
	i32 code;
} NutError;

NutError* ErrCache      = { NULL };
u32       ErrCacheIndex = 0;


NutError NullError() {
	return (NutError) {
		"",
		0
	};
}

i8 IsNullError(NutError n) {
	if (n.msg == NULL && n.code == NULL) {
		return TRUE;
	}

	return FALSE;
}

NutError ERROR(String msg, i32 code) {
	NutError e = {
		msg,
		code
	};

	ErrCache[ErrCacheIndex] = e;
	return e;
}

NutError CheckOut4Errors() {
	NutError e;

	for (i32 i = 0; !IsNullError(ErrCache[i]); i++) {
		e = ErrCache[i];
		ErrCache[i] = NullError();
		return e; 
	}

	return NullError();
}

function clear_errors() {
	ErrCache = 0;
	return;
}

#endif //nut error header