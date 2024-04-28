# fits.h
## What does it do?
Helps with casting by minimizing the amount of code you need to type to check for overflows. 
<br>The macro works by generating a bunch of helper functions that can be used to see if a value can SAFELY fit in a particular type. 
<br>See [example.c](https://github.com/jdarge/fits.h/blob/main/example.c) for more details.
##### NOTE: returns 1 if it's safe, or returns 0 if it's not safe.
## How do I call the helper functions?
Inside of fits.h you will see a bunch of typedefs, these are used as ##_fits(...) where ## is the type you want to check.
<br>See [generic_tests.c](https://github.com/jdarge/fits.h/blob/main/generic_tests.c) for more details, or alternatively view the bottom of this [README.md](#list-of-types)
## How can I use this?
This is just a simple header file. Just include it into your project like any other :)
## Compiling
#### 1. generic test cases
```
$ gcc generic_tests.c -o tests
$ ./tests
```
#### 2. example
```
$ gcc example.c -o example
$ ./example
```
#### e. stdint example
```
$ gcc stdint_test.c - stdint
$ ./stdint
```
## List of types:
standard:
```
unsigned long long   == ull  -> ull_fits(value)
unsigned long        == ul   -> ul_fits(value)  
unsigned int         == ui   -> ui_fits(value)
unsigned short       == us   -> us_fits(value)
unsigned char        == uc   -> uc_fits(value)

signed long long     == sll  -> sll_fits(value)
signed long          == sl   -> sl_fits(value)
signed int           == si   -> si_fits(value)
signed short         == ss   -> ss_fits(value)
signed char          == sc   -> sc_fits(value)
```
alternative standard:
```
signed long         == long  -> long_fits(value)
signed int          == int   -> int_fits(value)
signed short        == short -> short_fits(value)
signed char         == char  -> char_fits(value)
```
stdint:
```
uintmax_t           == umax  -> umax_fits(value)
uint8_t             == u8    -> u8_fits(value)
uint16_t            == u16   -> u16_fits(value)
uint32_t            == u32   -> u32_fits(value)
uint64_t            == u64   -> u64_fits(value)
uint_least8_t       == ul8   -> ul8_fits(value)
uint_least16_t      == ul16  -> ul16_fits(value)
uint_least32_t      == ul32  -> ul32_fits(value)
uint_least64_t      == ul64  -> ul64_fits(value)
uint_fast8_t        == uf8   -> uf8_fits(value)
uint_fast16_t       == uf16  -> uf16_fits(value)
uint_fast32_t       == uf32  -> uf32_fits(value)
uint_fast64_t       == uf64  -> uf64_fits(value)
uintptr_t           == uptr  -> uptr_fits(value)

intmax_t            == imax  -> imax_fits(value)
int8_t              == i8    -> i8_fits(value)
int16_t             == i16   -> i16_fits(value)
int32_t             == i32   -> i32_fits(value)
int64_t             == i64   -> i64_fits(value)
int_least8_t        == il8   -> il8_fits(value)
int_least16_t       == il16  -> il16_fits(value)
int_least32_t       == il32  -> il32_fits(value)
int_least64_t       == il64  -> il64_fits(value)
int_fast8_t         == if8   -> if8_fits(value)
int_fast16_t        == if16  -> if16_fits(value)
int_fast32_t        == if32  -> if32_fits(value)
int_fast64_t        == if64  -> if64_fits(value)
intptr_t            == iptr  -> iptr_fits(value)
```
