#ifndef FITS_H
#define FITS_H

#include <stdbool.h>
#include <limits.h>

// Typedefs for various types
typedef unsigned long long ull;
typedef unsigned long ul;
typedef unsigned int ui;
typedef unsigned short us;
typedef unsigned char uc;

typedef signed long long sll;
typedef signed long sl;
typedef signed int si;
typedef signed short ss;
typedef signed char sc;

// Macro definition for checking range
#define CHECK_RANGE(value, min, max) ((value) >= (min) && (value) <= (max))

#define IS_POSITIVE(value) ((value) >= -1)
#define GT_SLL(value) ((ull)(value) > LLONG_MAX)

// Macro definition for defining check functions
#define DEFINE_CHECK_FUNCTION(type, min, max)                   \
    bool type##_fits(ull val) {                                 \
        if (GT_SLL(val) && IS_POSITIVE((sll)val)) {             \
            return CHECK_RANGE((ull)val, (ull)min, (ull)max);   \
        } else {                                                \
            return CHECK_RANGE((sll)val, (sll)min, (sll)max);   \
        }                                                       \
    }                                                           \

// Define check functions for each type
DEFINE_CHECK_FUNCTION(ull,  0,          ULLONG_MAX)
DEFINE_CHECK_FUNCTION(ul,   0,          ULONG_MAX)
DEFINE_CHECK_FUNCTION(ui,   0,          UINT_MAX)
DEFINE_CHECK_FUNCTION(us,   0,          USHRT_MAX)
DEFINE_CHECK_FUNCTION(uc,   0,          UCHAR_MAX)
DEFINE_CHECK_FUNCTION(sll,  LLONG_MIN,  LLONG_MAX)
DEFINE_CHECK_FUNCTION(sl,   LONG_MIN,   LONG_MAX)
DEFINE_CHECK_FUNCTION(si,   INT_MIN,    INT_MAX)
DEFINE_CHECK_FUNCTION(ss,   SHRT_MIN,   SHRT_MAX)
DEFINE_CHECK_FUNCTION(sc,   SCHAR_MIN,  SCHAR_MAX)

/*
OPTIONAL:
    ...
*/
DEFINE_CHECK_FUNCTION(long,  LONG_MIN,  LONG_MAX)
DEFINE_CHECK_FUNCTION(int,   INT_MIN,   INT_MAX)
DEFINE_CHECK_FUNCTION(short, SHRT_MIN,  SHRT_MAX)
DEFINE_CHECK_FUNCTION(char,  SCHAR_MIN, SCHAR_MAX)

//  __LINUX__                      __OpenBSD__
#if defined(_GCC_WRAP_STDINT_H) || defined(_SYS_STDINT_H_)

#include <stdint.h>

typedef intmax_t      imax;
typedef int8_t        i8;
typedef int16_t       i16;
typedef int32_t       i32;
typedef int64_t       i64;
typedef int_least8_t  il8;
typedef int_least16_t il16;
typedef int_least32_t il32;
typedef int_least64_t il64;
typedef int_fast8_t   if8;
typedef int_fast16_t  if16;
typedef int_fast32_t  if32;
typedef int_fast64_t  if64;
typedef intptr_t      iptr;

DEFINE_CHECK_FUNCTION(imax, INTMAX_MIN,      INTMAX_MAX)
DEFINE_CHECK_FUNCTION(i8,   INT8_MIN,        INT8_MAX)
DEFINE_CHECK_FUNCTION(i16,  INT16_MIN,       INT16_MAX)
DEFINE_CHECK_FUNCTION(i32,  INT32_MIN,       INT32_MAX)
DEFINE_CHECK_FUNCTION(i64,  INT64_MIN,       INT64_MAX)
DEFINE_CHECK_FUNCTION(il8,  INT_LEAST8_MIN,  INT_LEAST8_MAX)
DEFINE_CHECK_FUNCTION(il16, INT_LEAST16_MIN, INT_LEAST16_MAX)
DEFINE_CHECK_FUNCTION(il32, INT_LEAST32_MIN, INT_LEAST32_MAX)
DEFINE_CHECK_FUNCTION(il64, INT_LEAST64_MIN, INT_LEAST64_MAX)
DEFINE_CHECK_FUNCTION(if8,  INT_FAST8_MIN,   INT_FAST8_MAX)
DEFINE_CHECK_FUNCTION(if16, INT_FAST16_MIN,  INT_FAST16_MAX)
DEFINE_CHECK_FUNCTION(if32, INT_FAST32_MIN,  INT_FAST32_MAX)
DEFINE_CHECK_FUNCTION(if64, INT_FAST64_MIN,  INT_FAST64_MAX)
DEFINE_CHECK_FUNCTION(iptr, INTPTR_MIN,      INTPTR_MAX)

typedef uintmax_t      umax;
typedef uint8_t        u8;
typedef uint16_t       u16;
typedef uint32_t       u32;
typedef uint64_t       u64;
typedef uint_least8_t  ul8;
typedef uint_least16_t ul16;
typedef uint_least32_t ul32;
typedef uint_least64_t ul64;
typedef uint_fast8_t   uf8;
typedef uint_fast16_t  uf16;
typedef uint_fast32_t  uf32;
typedef uint_fast64_t  uf64;
typedef uintptr_t      uptr;

DEFINE_CHECK_FUNCTION(umax, 0, UINTMAX_MAX)
DEFINE_CHECK_FUNCTION(u8,   0, UINT8_MAX)
DEFINE_CHECK_FUNCTION(u16,  0, UINT16_MAX)
DEFINE_CHECK_FUNCTION(u32,  0, UINT32_MAX)
DEFINE_CHECK_FUNCTION(u64,  0, UINT64_MAX)
DEFINE_CHECK_FUNCTION(ul8,  0, UINT_LEAST8_MAX)
DEFINE_CHECK_FUNCTION(ul16, 0, UINT_LEAST16_MAX)
DEFINE_CHECK_FUNCTION(ul32, 0, UINT_LEAST32_MAX)
DEFINE_CHECK_FUNCTION(ul64, 0, UINT_LEAST64_MAX)
DEFINE_CHECK_FUNCTION(uf8,  0, UINT_FAST8_MAX)
DEFINE_CHECK_FUNCTION(uf16, 0, UINT_FAST16_MAX)
DEFINE_CHECK_FUNCTION(uf32, 0, UINT_FAST32_MAX)
DEFINE_CHECK_FUNCTION(uf64, 0, UINT_FAST64_MAX)
DEFINE_CHECK_FUNCTION(uptr, 0, UINTPTR_MAX)

#endif /* STDINT */

#endif /* FITS */
