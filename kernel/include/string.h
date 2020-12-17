#ifndef __NUT_STRING_H__
#define __NUT_STRING_H__

#include <nut/types.h>


int strlen(String str) {
    int i = 0;
    while (str[i])
        i++;
    return i;
}

int strcmp(String s1, String s2) {
    int i = 0;
    while (s1[i] && s2[i]) {
        if (s1[i] < s2[i])
            return -1;
        else if (s1[i] > s2[i])
            return 1;
        i++;
    }
    return s1[i] - s2[i];
}

int strncmp(String s1, String s2, int len) {
    int i = 0;
    while (i < len) {
        if (s1[i] < s2[i])
            return -1;
        else if (s1[i] > s2[i])
            return 1;
        i++;
    }
    return 0;
}

String strcpy(String dest, String src) {
    int i = 0;
    while (src[i]) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = 0;
    return dest;
}

String strncpy(String dest, String src, int len) {
    int i = 0;
    int beyond = 0;
    while (i < len) {
        if (beyond == 0) {
            dest[i] = src[i];
            if (src[i] == 0)
                beyond = 1;
        }
        else {
            dest[i] = 0;
        }
        i++;
    }
    return dest;
}

int __format(String buffer,
    int val,
    int width,
    int zeropad,
    int base,
    int hexprefix)
{
    int bi = 0;
    char pb[10];
    int pbi = 0;

    if (hexprefix == 1) {
        buffer[0] = '0';
        buffer[1] = 'x';
        bi = 2;
        if (width > 2)
            width -= 2;
        else
            width = 0;
    }

    while (pbi < 10) {
        pb[pbi] = '0';
        pbi++;
    }

    if (base == 10)
        __str_base10(pb, val);
    else if (base == 16)
        __str_base16(pb, val);
    else
        abort();

    while (width > 10) {
        if (zeropad == 1)
            buffer[bi] = '0';
        else
            buffer[bi] = ' ';
        bi++;
        width--;
    }


    if (width == 0) {
        int c = 0;
        int started = 0;

        while (c < 10) {
            if (pb[c] != '0')
                started = 1;
            if (started) {
                buffer[bi] = pb[c];
                bi++;
            }
            c++;
        }

        if (started == 0) {
            buffer[bi] = '0';
            bi++;
        }
    }
    else {
        int c = 10 - width;
        int started = 0;
        while (c < 10) {
            if (pb[c] != '0')
                started = 1;
            if (started)
                buffer[bi] = pb[c];
            else if (zeropad == 1)
                buffer[bi] = '0';
            else
                buffer[bi] = ' ';
            bi++;
            c++;
        }
    }
    return bi;
}

#endif //nut string module