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

#endif
