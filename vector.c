#include <stdio.h>
#include <stdlib.h>

#include "vector.h"
#include "int.h"
#include "float.h"

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

errors freeVector(vectors* vector){

	free(vector->x);
    	free(vector->y);
    	free(vector->z);
    	free(vector);
	return success;

}

errors vectorDelete(vectors* v1){

	freeVector(v1);
	

}


errors printVectors(vectors* v1[], const int* vectorCount){


	if(*vectorCount < 0){
		printf("\nno available vectors\n\n");
		return failedToPrint;
	}
	for(int i = 0; i <= *vectorCount; i++) {
   	char* x_str = v1[i]->type->print(v1[i]->x);
    	char* y_str = v1[i]->type->print(v1[i]->y);
    	char* z_str = v1[i]->type->print(v1[i]->z);

    	if(v1[i]->type == getIntType()) {
        	printf("%d-int vector (%s, %s, %s)\n", i+1, x_str, y_str, z_str);
    	} else {
        	printf("%d-float vector (%s, %s, %s)\n", i+1, x_str, y_str, z_str);
    	  }

	}return success;

}

/*int checkType(const void* x, const void* y, const void* z){

	if(*(float*)x == *(int*)x && *(float*)y == *(int*)y && *(float*)z == *(int*)z){
		return 0; // int type
	}else return 1; // float type
}*/
