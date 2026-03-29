#ifndef IO_H
#define IO_H

#include "errors.h"
#include <time.h>
#include <stdio.h>


int delay(int milliseconds);

int inputCheck(char* x);//to check if input is correct

int typeAssign(char* x, char* y, char* z, float* tempX, float* tempY, float* tempZ);

int waitForEnter();

#ifdef _WIN32
    #define CLEAR_SCREEN() system("cls")
#else
    #define CLEAR_SCREEN() system("clear")
#endif


#endif
