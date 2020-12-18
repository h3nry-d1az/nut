/* See more kernel developing
info in wiki.osdev.org */
#ifndef __NUT_KERNEL__
#define __NUT_KERNEL__

void NutInit() { return; };
const char* NUT_VERSION = "v0.2.3";

#include <nut/types.h>
#include <nut/utils.h>
#include <nut/colors.h>
#include <nut/basics.h>
#include <nut/io.h>

#include "functions.h"
#include "log.h"
#include "abort.h"
#include "files.h"
#include "network.h"
//modules

#endif //nut kernel header