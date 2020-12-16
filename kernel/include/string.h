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

#endif //nut string module