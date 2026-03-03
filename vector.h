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
}vector;

vectorAdd(const vector* v1, const vector*v2, vector* result);


#endif
