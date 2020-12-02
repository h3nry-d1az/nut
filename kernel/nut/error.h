#ifndef __NUT_ERROR_H__
#define __NUT_ERROR_H__

typedef struct __NutError__ {
	String msg;
	i32 code;
} NutError;

NutError* ErrCache      = { NULL };
u32       ErrCacheIndex = 0;


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

function CheckOut4Errors() {
	for (i32 i = 0; !IsNullError(ErrCache[i]); i++) {
		panic(ErrCache[i].msg);
	}

	return;
}

#endif //nut error header