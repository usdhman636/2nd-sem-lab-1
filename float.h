#ifndef FLOAT_H
#define FLOAT_H

#include "itype.h"

int floatAdd(const void* arg1, const void* arg2, void* result);
int floatDotProduct(const void* arg1, const void* arg2, void* result);
char* floatPrint(const void* result);

itype* getFloatType();

#endif
