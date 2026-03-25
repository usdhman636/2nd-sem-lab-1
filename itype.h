#ifndef ITYPE_H
#define ITYPE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int (*add)(const void* arg1, const void* arg2, void* result);
    int (*dotProduct)(const void* arg1, const void* arg2, void* result);
    char* (*print)(const void* result);
}itypeFunc;

typedef struct {
    size_t size;
    int value; // 0 for int , 1 for float
    itypeFunc *func;
} itype;

#endif
