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

vector* creatVector(itype* type, void* x, void* y, void* z, errors* result);

errors vectorAdd(const vector* v1, const vector* v2, vector* result);

errors vectorDotProduct(const vector* v1, const vector* v2, void* result);

errors vectorDelete(vector* v1);

errors freeVector(vector* v1);

int checkType(const float* x, const float* y, const float* z);

#endif
