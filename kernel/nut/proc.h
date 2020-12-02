#ifndef __NUT_PROCESS_H__
#define __NUT_PROCESS_H__

#include <stdlib.h>

#include <sys/types.h>
#include <sys/wait.h>


typedef struct __NutProc__ {
	String name;
	value_ptr main;
	void* Stack;
	i32 PID;
} NutProc;


NutProc InitProcess(String name, size_t stack_size, value_ptr child_main) {
	NutProc n = {
		name,
		child_main,
		malloc(stack_size)
	};

	n.PID = clone(n.main, n.Stack, SIGCHLD);

	return n;
}

#endif //nut process header
