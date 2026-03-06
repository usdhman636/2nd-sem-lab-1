#ifndef IO_H
#define IO_H

#include "errors.h"
#include <time.h>
#include <stdio.h>


int delay(int milliseconds);

int createVectorScan(char* x, char* y, char* z, float* tempX, float* tempY, float* tempZ);

int waitForEnter();

#ifdef _WIN32
    #define CLEAR_SCREEN() system("cls")
#else
    #define CLEAR_SCREEN() system("clear")
#endif


#endif
