#if !defined(__NUT_ARM_FILE_H__) && \
     (defined(__ARM64__) || defined(__ARM32__) || \
      defined(__RASPBERRYPI_2__) || defined(__RASPBERRYPI_34__) || \
      defined(__RASPBERRYPI_ABZERO__))
#define __NUT_ARM_FILE_H__

#include <nut/types.h>
#include <nut/arm/syscalls.h>

typedef int FILE;



FILE* fopen(String filename, String mode) {
    if (!strcmp(mode, "wb"))
        return __syscall(__syscall_open, filename, 65, 0x1fd);
    if (!strcmp(mode, "rb"))
        return __syscall(__syscall_open, filename, 0, 0);
    abort();
}

int fclose(FILE* stream) {
    __syscall(__syscall_close, stream);
    return 0;
}

int fgetc(FILE* stream) {
    char buf;
    int r = __syscall(__syscall_read, stream, &buf, 1);
    if (r <= 0)
        return -1;
    return buf;
}

String fgets(String str, int n, FILE* stream) {
    int i = 0;
    do {
        char c = fgetc(stream);
        if (c == -1 || c == 255) {
            if (i == 0)
                return NULL;

            str[i] = 0;
            return str;
        }
        str[i] = c;
        i++;
    } while (str[i - 1] != '\n');

    str[i] = 0;
    return str;
}

int fputc(int c, FILE* stream) {
    char buf[1];
    buf[0] = c;
    __syscall(__syscall_write, stream, &buf, 1);
    return 0;
}

#endif //nut ARM file module