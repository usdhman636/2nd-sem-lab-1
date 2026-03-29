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

int typeAssign(char* x, char* y, char* z, float* tempX, float* tempY, float* tempZ){
    char *endptr;
    int hasFloat = 0;

	while(1){
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
	}

	while(1){
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
	}

	while(1){
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
	}

    return hasFloat;//0 for int || 1 for float
}

int inputCheck(char* x){

	char* endptr;

        long intValue = strtol(x, &endptr, 10);

        if (*endptr == '\0') {
            return 0;//success
        }

        float floatValue = strtof(x, &endptr);

        if (*endptr == '\0') {
            return 0;//success
        }else return 1;// fail

}

int waitForEnter(){
    printf("\nНажмите ENTER для продолжения...");
    clear_input_buffer();
    return 0;
}
