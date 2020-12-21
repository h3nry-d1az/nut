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

#endif //nutlisp ALU (arithmetic logic unit)