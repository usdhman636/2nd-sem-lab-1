#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

vectors* createVector(itype* TYPE, void* x, void* y, void* z, errors* result){

	vectors* vector = malloc(sizeof(vectors));
        if (vector == NULL) {
        	*result = memoAlocFailed;
        	exit(1);
    }
	vector->type = TYPE;
	vector->x = malloc(TYPE->size);
	vector->y = malloc(TYPE->size);
	vector->z = malloc(TYPE->size);
	if (vector->x == NULL || vector->y == NULL || vector->z == NULL){
		*result = memoAlocFailed;
		exit(1);
	}
	memcpy(vector->x, x, TYPE->size);
	memcpy(vector->y, y, TYPE->size);
	memcpy(vector->z, z, TYPE->size);
	*result = success;
	return vector;
}

errors vectorAdd(const vectors* v1, const vectors* v2, vectors* result){

	if(v1->type != v2->type) return differentTypes;
	v1->type->add(v1->x, v2->x, result->x);
        v1->type->add(v1->y, v2->y, result->y);
        v1->type->add(v1->z, v2->z, result->z);

        return success;
}

errors vectorDotProduct(const vectors* v1, const vectors* v2, void* result);

errors vectorDelete(vectors* v1);

errors freeVector(vectors* v1);

/*int checkType(const void* x, const void* y, const void* z){

	if(*(float*)x == *(int*)x && *(float*)y == *(int*)y && *(float*)z == *(int*)z){
		return 0; // int type
	}else return 1; // float type
}*/
