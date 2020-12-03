#ifndef __NUT_PYTHON_H__
#define __NUT_PYTHON_H__

#include <Python.h>


typedef struct __PythonScript__ {
	String name;
	String code;
} ScriptPy;
//Structure


ScriptPy ScriptPyInit(String name, String code) {
	return {
		name,
		code
	};
}

void ScriptPyRun(ScriptPy script) {
	Py_SetProgramName(script.name);
	PyRun_SimpleString(script.code);

	return;
}

#endif //nut python scripts header
