#include <stdio.h>
#include <stdlib.h>

#include "vector.h"
#include "int.h"
#include "float.h"

vectors* createVector(itype* TYPE, float x, float y, float z, errors* result){

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
	if (TYPE == getIntType()) {
        	int ix = (int) x;
	        int iy = (int) y;
	        int iz = (int) z;
	        memcpy(vector->x, &ix, TYPE->size);
	        memcpy(vector->y, &iy, TYPE->size);
	        memcpy(vector->z, &iz, TYPE->size);
        }else {
	        memcpy(vector->x, &x, TYPE->size);
	        memcpy(vector->y, &y, TYPE->size);
	        memcpy(vector->z, &z, TYPE->size);
    }
	*result = success;
	return vector;
}

vectors* vectorAdd(vectors* v1[], const int* add1, const int* add2){


	vectors* vecRes = malloc(sizeof(vectors));

	if(v1[*add1]->type->value == 0){

		vecRes->type = getIntType();
		vecRes->x = malloc(vecRes->type->size);
		vecRes->y = malloc(vecRes->type->size);
		vecRes->z = malloc(vecRes->type->size);

	}else {

		vecRes->type = getFloatType();
		vecRes->x = malloc(vecRes->type->size);
                vecRes->y = malloc(vecRes->type->size);
                vecRes->z = malloc(vecRes->type->size);
	}

	v1[*add1]->type->add(v1[*add1]->x, v1[*add2]->x, vecRes->x);
        v1[*add1]->type->add(v1[*add1]->y, v1[*add2]->y, vecRes->y);
        v1[*add1]->type->add(v1[*add1]->z, v1[*add2]->z, vecRes->z);

        return vecRes;
}

errors vectorDotProduct(const vectors* v1, const vectors* v2, void* result);

errors freeVector(vectors* vector){

	free(vector->x);
    	free(vector->y);
    	free(vector->z);
    	free(vector);
	return success;

}

errors vectorDelete(vectors* v1[], int* vectorCount, const int* deleteOpt){


	if(*deleteOpt - 1 == *vectorCount){
                        freeVector(v1[*vectorCount]);
                        printf("\nvector deleted\n\n");
			*vectorCount -= 1;
                        return success;
        }
	for(int i = *deleteOpt - 1; i < *vectorCount; i++){
		freeVector(v1[i]);
		v1[i] = malloc(sizeof(vectors));
     		if (v1[i] == NULL) {
                	return memoAlocFailed;
    		}
		if(v1[i + 1]->type == getIntType()){

			v1[i]->type = getIntType();
			v1[i]->x = malloc(v1[i]->type->size);
			v1[i]->y = malloc(v1[i]->type->size);
			v1[i]->z = malloc(v1[i]->type->size);
		}else {
			v1[i]->type = getFloatType();
			v1[i]->x = malloc(v1[i]->type->size);
                        v1[i]->y = malloc(v1[i]->type->size);
                        v1[i]->z = malloc(v1[i]->type->size);
		}
		if (v1[i]->x == NULL || v1[i]->y == NULL || v1[i]->z == NULL){
                return  memoAlocFailed;
        	}
		memcpy(v1[i]->x, v1[i + 1]->x, v1[i]->type->size);
		memcpy(v1[i]->y, v1[i + 1]->y, v1[i]->type->size);
		memcpy(v1[i]->z, v1[i + 1]->z, v1[i]->type->size);
	}// for
	printf("\n vector deleted\n\n");
	*vectorCount -= 1;
	return success;

}


errors printVectors(vectors* v1[], const int* vectorCount){


	if(*vectorCount < 0){
		printf("\nno available vectors\n\n");
		return failedToPrint;
	}
	for(int i = 0; i <= *vectorCount; i++) {
   	char* x_str = v1[i]->type->print(v1[i]->x);
	if(v1[i]->type == getIntType()) {
                printf("%d-int vector (%s", i+1, x_str);
        } else {
                printf("%d-float vector (%s", i+1, x_str);
          }

    	      x_str = v1[i]->type->print(v1[i]->y);
	printf(", %s",x_str);

    	      x_str = v1[i]->type->print(v1[i]->z);
	printf(", %s)\n",x_str);

	}return success;

}

int checkType(vectors* v1[], int* add1, int* add2){
	printf("haha");
	if(v1[*add1]->type->value != v1[*add2]->type->value){
		return -1; // different types
	}else if(v1[*add1]->type->value == 0){
		 return 0; // int type
	}else return 1; // float type
}
