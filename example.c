#include <stdio.h>
#include <string.h>

#include "fits.h"

int main(void) {

    int value = 125;

    for(int i = 0; i < 5; i++) {
        value++;
    }

    signed char c;
    if(!sc_fits(value)) {
        // Handle case where value is too large.

        printf("This value CANNOT safely be casted to a char and assigned to c.\n");
        printf("Value: %d\nchar Max: %d\n", value, CHAR_MAX);
        
        return 1;
    } 

    printf("This value CAN safely be casted to a char and assigned to c.\n");
    c = (char) value;

    return 0;
}