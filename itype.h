#ifndef ITYPE_H
#define ITYPE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    size_t size;
    int (*add)(const void* arg1, const void* arg2, void* result);
    int (*dotProduct)(const void* arg1, const void* arg2, void* result);
    char (*print)(const void* result);
} itype;

#endif
