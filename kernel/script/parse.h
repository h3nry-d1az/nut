#ifndef __NUT_LISP_PARSER_H__
#define __NUT_LISP_PARSER_H__

int parse(String expression) {
    if (*(expression++) != '(') {
        puts("ERROR: must begin with a '(' \n");
        puts("In expression: ");
        puts(expression);
        puts("\n");

        return 1; //not a valid expression
    }
    char* op = *(expression++);

    int result = 0;
    switch (op) {
    case ADD:
        result = nutlispADD(expression);
        break;
    default: break;
    }

	return 0; //valid expression
}

#endif //nutlisp parser