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

vectors** initiateVecArr();

vectors** reallocVec(vectors** v1, int* arrCount);

vectors* createVector(itype* type, float x, float y, float z, errors* result);

vectors* vectorAdd(vectors* v1[], const int* add1, const int* add2);

int vectorDotProduct(vectors* v1[], int* arg1, int* arg2, int* iDotProd, float* fDotProd);

errors vectorDelete(vectors* v1[], int* vectorCount, const int* deleteOpt);

errors freeVector(vectors* v1);

errors printVectors(vectors* v1[], const int* vectorCount);

errors printOneVector(vectors* v1[], const int* arg);

int checkType(vectors* v1[], int add1, int add2);

errors endProgram(vectors** v1, const int* vectorCount);

#endif
