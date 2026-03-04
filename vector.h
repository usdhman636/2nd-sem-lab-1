#ifndef VECTOR_H
#define VECTOR_H

#include "itype.h"
#include "int.h"
#include "float.h"
#include "errors.h"


typedef struct{
	void* x;
	void* y;
	void* z;
	itype* type;
}vectors;

vectors* createVector(itype* type, float x, float y, float z, errors* result);

vectors* vectorAdd(vectors* v1[], const int* add1, const int* add2);

errors vectorDotProduct(const vectors* v1, const vectors* v2, void* result);

errors vectorDelete(vectors* v1[], int* vectorCount, const int* deleteOpt);

errors freeVector(vectors* v1);

errors printVectors(vectors* v1[], const int* vectorCount);

int checkType(vectors* v1[], int* add1, int* add2);

#endif
