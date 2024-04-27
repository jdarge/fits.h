#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "fits.h"

int main(void) {

    // You can use either definition...
    // uint16_t value = 250;
    u16 value = 250;

    if(!u8_fits(value)) {
        // This should not be true since UINT8_MAX is 255
        printf("Unknown logic error, exiting...");
        return 1;
    }

    for(int i = 0; i < 10; i++) {
        value++;
    }

    if(!u8_fits(value)) {
        // Handle case where value is too large.

        printf("This value CANNOT safely be casted to a uint8_t and assigned to c.\n");
        printf("Value: %d\nchar Max: %d\n", value, UINT8_MAX);
        
        return 1;
    } 

    printf("This value CAN safely be casted to a uint8_t and assigned to c.\n");
    u8 c = (u8) value;

    return 0;
}
