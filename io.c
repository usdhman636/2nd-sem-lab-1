#include "io.h"
#include "errors.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int delay(int milliseconds) {
    long pause;
    clock_t t1, t2;

    pause = milliseconds * (CLOCKS_PER_SEC / 1000);
    t1 = t2 = clock();

    while ((t1 - t2) < pause) {
        t1 = clock();
    }
    return 0;
}

int createVectorScan(char* x, char* y, char* z, float* tempX, float* tempY, float* tempZ){
    char *endptr;
    int hasFloat = 0;

    while (1) {
        printf("\nEnter x value: ");

        if (scanf("%9s", x) != 1) {
            clear_input_buffer();
            printf("\nInvalid input, try again.\n");
            continue;
        }

	clear_input_buffer();
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

        printf("\nInvalid number, try again.\n");
    }

    while (1) {
        printf("\nEnter y value: ");

        if (scanf("%9s", y) != 1) {
            clear_input_buffer();
            printf("\nInvalid input, try again.\n");
            continue;
        }

	clear_input_buffer();
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

        printf("\nInvalid number, try again.\n");
    }

    while (1) {
        printf("\nEnter z value: ");

        if (scanf("%9s", z) != 1) {
            clear_input_buffer();
            printf("\nInvalid input, try again.\n");
            continue;
        }

	clear_input_buffer();
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

        printf("\nInvalid number, try again.\n");
    }

    return hasFloat;//0 for int || 1 for float
}


int waitForEnter(){
    printf("\nPress ENTER to continue...");
    clear_input_buffer();
    return 0;
}
