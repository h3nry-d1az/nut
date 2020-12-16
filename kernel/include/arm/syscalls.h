#if !defined(__NUT_ARM_SYSCALLS_H__) && \
     (defined(__ARM64__) || defined(__ARM32__) || \
      defined(__RASPBERRYPI_2__) || defined(__RASPBERRYPI_34__) || \
      defined(__RASPBERRYPI_ABZERO__))
#define __NUT_ARM_SYSCALLS_H__

#define __syscall_exit 1
#define __syscall_read 3
#define __syscall_write 4
#define __syscall_close 6
#define __syscall_open 5
#define __syscall_brk 45

#endif //nut ARM syscalls module