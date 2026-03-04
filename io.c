#include "io.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int createVectorScan(char* x, char* y, char* z, float* tempX, float* tempY, float* tempZ){
    char *endptr;
    int hasFloat = 0;

    while (1) {
        printf("\nEnter x value: ");

        if (scanf("%9s", x) != 1) {
            clear_input_buffer();
            printf("Invalid input, try again.\n");
            continue;
        }

        long intValue = strtol(x, &endptr, 10);

        if (*endptr == '\0') {
            *tempX = (float)intValue;
            break;
        }

        float floatValue = strtof(x, &endptr);

        if (*endptr == '\0') {
            *tempX = floatValue;
            hasFloat = 1;
            break;
        }

        printf("Invalid number, try again.\n");
        clear_input_buffer();
    }

    while (1) {
        printf("\nEnter y value: ");

        if (scanf("%9s", y) != 1) {
            clear_input_buffer();
            printf("Invalid input, try again.\n");
            continue;
        }

        long intValue = strtol(y, &endptr, 10);

        if (*endptr == '\0') {
            *tempY = (float)intValue;
            break;
        }

        float floatValue = strtof(y, &endptr);

        if (*endptr == '\0') {
            *tempY = floatValue;
            hasFloat = 1;
            break;
        }

        printf("Invalid number, try again.\n");
        clear_input_buffer();
    }

    while (1) {
        printf("\nEnter z value: ");

        if (scanf("%9s", z) != 1) {
            clear_input_buffer();
            printf("Invalid input, try again.\n");
            continue;
        }

        long intValue = strtol(z, &endptr, 10);

        if (*endptr == '\0') {
            *tempZ = (float)intValue;
            break;
        }

        float floatValue = strtof(z, &endptr);

        if (*endptr == '\0') {
            *tempZ = floatValue;
            hasFloat = 1;
            break;
        }

        printf("Invalid number, try again.\n");
        clear_input_buffer();
    }

    return hasFloat;//0 for int || 1 for float
}
