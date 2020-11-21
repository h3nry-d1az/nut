#ifndef NUT_TYPES_H
#define NUT_TYPES_H

typedef void function;

typedef void*       var;
typedef const void* val;

typedef char      i8;
typedef short     i16;
typedef int       i32;
typedef long      i64;
typedef long long i128;

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef unsigned long      u64;
typedef unsigned long long u128;

typedef signed char      s8;
typedef signed short     s16;
typedef signed int       s32;
typedef signed long      s64;
typedef signed long long s128;

typedef float       f32;
typedef double      f64;
typedef long double f128;

typedef char           str[];
typedef char*          String;

#endif //nut data types