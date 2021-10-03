#ifndef __NUTVM_SETTINGS_H__
#define __NUTVM_SETTINGS_H__

// nutVM memory array size
// expressed in KB (1024 B).
//
// Default is 1024 KB size
// (1 MB, 1048576 B => 2^20 B).
#define MEMSIZE 1024

// nutVM PC (program counter)
// start position.
//
// Default is 0x3000
#define PCSTART 0x3000

// nutVM debug mode flag,
// default is FALSE.
#define DEBUGMD FALSE


#endif // !__NUTVM_SETTINGS_H__