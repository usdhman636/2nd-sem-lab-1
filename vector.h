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

vectors* createVector(itype* type, void* x, void* y, void* z, errors* result);

errors vectorAdd(const vectors* v1, const vectors* v2, vectors* result);

errors vectorDotProduct(const vectors* v1, const vectors* v2, void* result);

errors vectorDelete(vectors* v1);

errors freeVector(vectors* v1);

//int checkType(const void* x, const void* y, const void* z);

#endif
