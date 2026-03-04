#ifndef ERRORS_H
#define ERRORS_H

#include <stdio.h>
#include <stdlib.h>

typedef enum {
	memoAlocFailed = 100,
	differentTypes = 200,
	failedToPrint = 300,
	success = 0,

}errors;

int clear_input_buffer();

#endif
