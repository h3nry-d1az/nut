#ifndef __NUT_UTILS_H__
#define __NUT_UTILS_H__

#define NULL 0
//NULL

#define len(arr) \
    sizeof(arr) / sizeof(arr[0])

u32 strlen(const String str) {
    u32 length = 0;
    while (str[length])
        length++;
    return length;
}

u32 digits(int num) {
    u32 count = 0;
    if (num == 0)
        return 1;

    while (num > 0) {
        count++;
        num = num / 10;
    }
    return count;
}

function ItoA(int num, String number) {
    int dgcount = digits(num);
    int index = dgcount - 1;
    char x;
    if (num == 0 && dgcount == 1) {
        number[0] = '0';
        number[1] = '\0';
    }
    else {
        while (num != 0) {
            x = num % 10;
            number[index] = x + '0';
            index--;
            num = num / 10;
        }
        number[dgcount] = '\0';
    }
}

function sleep(u32 timer_count) {
    while (1) {
        asm volatile("nop");
        timer_count--;
        if (timer_count <= 0)
            break;
    }
}

#endif //nut utils