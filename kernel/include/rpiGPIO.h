#ifndef __NUT_RASPBERRYPI_GPIO__
#define __NUT_RASPBERRYPI_GPIO__

/* raspberryPi GPIO registries */
#define GPFSEL0 0x7E200000 //GPIO Function Select 0
#define GPFSEL1 0x7E200004 //GPIO Function Select 1
#define GPFSEL2 0x7E200008 //GPIO Function Select 2
#define GPFSEL3 0x7E20000C //GPIO Function Select 3
#define GPFSEL4 0x7E200010 //GPIO Function Select 4
#define GPFSEL5 0x7E200014 //GPIO Function Select 5


#define GPSET0 0x7E20001C //GPIO Pin Output Set 0
#define GPSET1 0x7E200020 //GPIO Pin Output Set 1

#define GPCLR0 0x7E200028 //GPIO Pin Output Clear 0
#define GPCLR1 0x7E20002C //GPIO Pin Output Clear 1

#define GPLEV0 0x7E200034 //GPIO Pin Level 0
#define GPLEV1 0x7E200038 //GPIO Pin Level 1

#define GPEDS0 0x7E200040 //GPIO Pin Event Detect Status 0
#define GPEDS1 0x7E200044 //GPIO Pin Event Detect Status 1

#define GPREN0 0x7E20004C //GPIO Pin Rising Edge Detect Enable 0
#define GPREN1 0x7E200050 //GPIO Pin Rising Edge Detect Enable 1

#define GPFEN0 0x7E200058 //GPIO Pin Falling Edge Detect Enable 0
#define GPFEN1 0x7E20005C //GPIO Pin Falling Edge Detect Enable 1

#define GPHEN0 0x7E200064 //GPIO Pin High Detect Enable 0
#define GPHEN1 0x7E200068 //GPIO Pin High Detect Enable 1

#define GPLEN0 0x7E200070 //GPIO Pin Low Detect Enable 0
#define GPLEN1 0x7E200074 //GPIO Pin Low Detect Enable 1

#define GPAREN0 0x7E20007C //GPIO Pin Async. Rising Edge Detect 0
#define GPAREN1 0x7E200080 //GPIO Pin Async. Rising Edge Detect 1

#define GPAFEN0 0x7E200088 //GPIO Pin Async. Falling Edge Detect 0
#define GPAFEN1 0x7E20008C //GPIO Pin Async. Falling Edge Detect 1

#define GPPUD 0x7E200094 //GPIO Pin Pull-up/down Enable

#define GPPUDCLK0 0x7E200098 //GPIO Pin Pull-up/down Enable Clock 0
#define GPPUDCLK1 0x7E20009C //GPIO Pin Pull-up/down Enable Clock 1
/* info from: raspberrypi.org/app/uploads/2012/02/BCM2835-ARM-Peripherals.pdf
pages 89-108 */


#endif //raspberryPi GPIO module
