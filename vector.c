#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

vector* createVector(itype* type, void* x, void* y, void* z, errors* result){

	vectors* vector = malloc(sizeof(Vector));
        if (vector == NULL) {
        	*result = memoAlocFailed;
        	exit(1);
    }
	vector->itype = type;
	vector->x = malloc(type->size);
	vector->y = malloc(type->size);
	vector->z = malloc(type->size);
	if (vector->x == NULL || vector->y == NULL || vector->z == NULL){
		*result = memoAlocFailed;
		exit(1);
	}
	memcpy(vector->x, x, type->size);
	memcpy(vector->y, y, type->size);
	memcpy(vector->z, z, type->size);
	*result = ok;
	return vector;
}

errors vectorAdd(const vector* v1, const vector* v2, vector* result);{

	if(v1->itype != v2->itype) return differentTypes;
	v1->itype->add(v1->x, v2->x, result->x);
        v1->itype->add(v1->y, v2->y, result->y);
        v1->itype->add(v1->z, v2->z, result->z);

        return ok;
}

errors vectorDotProduct(const vector* v1, const vector* v2, void* result);

errors vectorDelete(vector* v1);

errors freeVector(vector* v1);

int checkType(const float* x, const float* y, const float* z){

	if(*x == *(int)x && *y == *(int)y && *z == *(int)z){
		return 0; // int type
	}else return 1; // float type
}
