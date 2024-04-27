/*



*/

/*

NOTES:
    all signed values start with 's'
    this was done with intent b/c of how the macros work...

    typedef signed int i;

    i is a common iterator and would cause conflict later down the road, im sure.
*/

#include <stdio.h>
#include <limits.h>
#include <string.h>
#include "fits.h"

int main() {

    /*
    
    Out of lazyness, and readability, I used the limit values to simulate overflow issues.
    Realistically you would pass a variable or value to this.

    */
    size_t example = strlen("hello");
    printf("Example:%d\n\n", si_fits(example));

    printf("Obvious Passes:\n");
    printf("ULL\t%d\n",  ull_fits(ULLONG_MAX));
    printf("UL\t%d\n",   ul_fits(ULONG_MAX));
    printf("SLL\t%d\n",  sll_fits(LLONG_MAX));
    printf("SL\t%d\n",   sl_fits(LONG_MAX));
    printf("UI\t%d\n",   ui_fits(UINT_MAX));
    printf("SI\t%d\n",   si_fits(INT_MAX));
    printf("US\t%d\n",   us_fits(USHRT_MAX));
    printf("SS\t%d\n",   ss_fits(SHRT_MAX));
    printf("UC\t%d\n",   uc_fits(UCHAR_MAX));
    printf("SC\t%d\n",   sc_fits(SCHAR_MAX));

    printf("SLL\t%d\n",  sll_fits(LLONG_MAX));
    printf("SL\t%d\n",   sl_fits(LONG_MAX));
    printf("SI\t%d\n",   si_fits(INT_MAX));
    printf("SS\t%d\n",   ss_fits(SHRT_MAX));
    printf("SC\t%d\n",   sc_fits(SCHAR_MAX));

    printf("\nObvious Fails:\n");
    printf("SLL\t%d\n",  sll_fits(ULONG_MAX));
    printf("SL\t%d\n",   sl_fits(ULONG_MAX));
    printf("SI\t%d\n",   si_fits(UINT_MAX));
    printf("US\t%d\n",   us_fits(USHRT_MAX+1));
    printf("SS\t%d\n",   ss_fits(USHRT_MAX));
    printf("UC\t%d\n",   uc_fits(UCHAR_MAX + 1));
    printf("SC\t%d\n",   sc_fits(ULONG_MAX));

    printf("ULL\t%d\n",  ull_fits(INT_MIN));
    printf("UL\t%d\n",   ul_fits(INT_MIN));
    printf("UI\t%d\n",   ui_fits(INT_MIN));
    printf("US\t%d\n",   us_fits(INT_MIN));
    printf("UC\t%d\n",   uc_fits(INT_MIN));

    // ???
    printf("\nUnresolved:\n");
    printf("UI\t%d\n",   ui_fits(UINT_MAX+1));
    printf("UI\t%u\n",  (UINT_MAX+1));

    return 0;
}
