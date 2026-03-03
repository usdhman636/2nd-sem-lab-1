#ifndef INT_H
#define INT_H

#include "itype.h"

int intAdd(const void* arg1, const void* arg2, void* result);
int intDotProduct(const void* arg1, const void* arg2, void* result);
int intPrint(const void* result);

itype* getIntType();

#endif
