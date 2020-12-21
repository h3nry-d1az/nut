#ifndef __NUT_LISP_ALU_H__
#define __NUT_LISP_ALU_H__

double nutlispADD(String expression) {
    double product = 0; //by default addition is 0

    while (*expression != ')') {
        if (*expression == ' ') {
            expression++; continue;
        }

        double m = atof(expression++);
        product += m;
    }

    return product;
}

double nutlispSUB(String expression) {
    double product = 0; //by default substraction is 0
    usize index = 0;

    while (*expression != ')') {
        if (*expression == ' ') {
            expression++; continue;
        }

        if (index == 0) {
            product = atof(expression++);
        } else {
            double m = atof(expression++);
            product -= m;
        }
        index++;
    }

    return product;
}

double nutlispMUL(String expression) {
    double product = 1; //by default multiplication is 1

    while (*expression != ')') {
        if (*expression == ' ') {
            expression++; continue;
        }

        double m = atof(expression++);
        product *= m;
    }

    return product;
}

#endif //nutlisp ALU (arithmetic logic unit)