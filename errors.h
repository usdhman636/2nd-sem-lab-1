#ifndef ERRORS_H
#define ERRORS_H

#include <stdio.h>
#include <stdlib.h>

typedef enum {
	memoAlocFailed = 100,
	differenTypes = 200,
	success = 0,

}errors;

int clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    return 0;
}

#endif
