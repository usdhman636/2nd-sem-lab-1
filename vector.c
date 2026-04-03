#include <stdio.h>
#include <stdlib.h>

#include "vector.h"
#include "int.h"
#include "float.h"

vectors** initiateVecArr(errors* opRes){

	vectors** vecArr = malloc(10 * sizeof(vectors*));

	if(vecArr == NULL){
		*opRes = memoAllocFailed;
		 exit(1);
	}
	*opRes = success;
	return vecArr;

}

vectors** reallocVec(vectors** v1, int* arrCount, errors* opRes){

	*arrCount += 10;
	vectors** tmpVec = realloc(v1,*arrCount * sizeof(vectors*));
	if(tmpVec == NULL){
		*opRes = memoAllocFailed;
		exit(1);
	}
	*opRes = success;
	return tmpVec;

}

vectors* createVector(itype* TYPE, float x, float y, float z, errors* opRes){

	vectors* vector = malloc(sizeof(vectors));
        if (vector == NULL) {
        	*opRes = memoAllocFailed;
        	exit(1);
    }
	vector->type = TYPE;
	vector->x = malloc(TYPE->size);
	vector->y = malloc(TYPE->size);
	vector->z = malloc(TYPE->size);
	if (vector->x == NULL || vector->y == NULL || vector->z == NULL){
		*opRes = memoAllocFailed;
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
	*opRes = success;
	return vector;
}

vectors* vectorAdd(vectors* v1[], const int* add1, const int* add2, errors* opRes){


	vectors* vecRes = malloc(sizeof(vectors));
	if(vecRes == NULL){
		*opRes = memoAllocFailed;
		exit(1);
	}

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

	if (vecRes->x == NULL || vecRes->y == NULL || vecRes->z == NULL){
                *opRes = memoAllocFailed;
                exit(1);
        }

	v1[*add1]->type->func->add(v1[*add1]->x, v1[*add2]->x, vecRes->x);
        v1[*add1]->type->func->add(v1[*add1]->y, v1[*add2]->y, vecRes->y);
        v1[*add1]->type->func->add(v1[*add1]->z, v1[*add2]->z, vecRes->z);

	*opRes = success;
        return vecRes;
}

int vectorDotProduct(vectors* v1[], int* arg1, int* arg2, int* iDotProd, float* fDotProd, errors* opRes){

	vectors* vecRes = malloc(sizeof(vectors));
	if(vecRes == NULL){
		*opRes = memoAllocFailed;
		exit(1);
	}

        if(v1[*arg1]->type->value == 0){

                vecRes->type = getIntType();
                vecRes->x = malloc(vecRes->type->size);
                vecRes->y = malloc(vecRes->type->size);
                vecRes->z = malloc(vecRes->type->size);
		if (vecRes->x == NULL || vecRes->y == NULL || vecRes->z == NULL){
                	*opRes = memoAllocFailed;
                	exit(1);
        	}

		v1[*arg1]->type->func->dotProduct(v1[*arg1]->x, v1[*arg2]->x, vecRes->x);
        	v1[*arg1]->type->func->dotProduct(v1[*arg1]->y, v1[*arg2]->y, vecRes->y);
        	v1[*arg1]->type->func->dotProduct(v1[*arg1]->z, v1[*arg2]->z, vecRes->z);

		*iDotProd = *(int*)vecRes->x + *(int*)vecRes->y + *(int*)vecRes->z;
		*opRes = success;
		return 0;

        }else {

                vecRes->type = getFloatType();
                vecRes->x = malloc(vecRes->type->size);
                vecRes->y = malloc(vecRes->type->size);
                vecRes->z = malloc(vecRes->type->size);
		if (vecRes->x == NULL || vecRes->y == NULL || vecRes->z == NULL){
                	*opRes = memoAllocFailed;
                	exit(1);
        	}

		v1[*arg1]->type->func->dotProduct(v1[*arg1]->x, v1[*arg2]->x, vecRes->x);
                v1[*arg1]->type->func->dotProduct(v1[*arg1]->y, v1[*arg2]->y, vecRes->y);
                v1[*arg1]->type->func->dotProduct(v1[*arg1]->z, v1[*arg2]->z, vecRes->z);

		*fDotProd = *(float*)vecRes->x + *(float*)vecRes->y + *(float*)vecRes->z;
                *opRes = success;
		return 1;

        }
}

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
			*vectorCount -= 1;
                        return success;
        }
	for(int i = *deleteOpt - 1; i < *vectorCount; i++){
		freeVector(v1[i]);
		v1[i] = malloc(sizeof(vectors));
     		if (v1[i] == NULL) {
                	return memoAllocFailed;
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
                return  memoAllocFailed;
        	}
		memcpy(v1[i]->x, v1[i + 1]->x, v1[i]->type->size);
		memcpy(v1[i]->y, v1[i + 1]->y, v1[i]->type->size);
		memcpy(v1[i]->z, v1[i + 1]->z, v1[i]->type->size);
	}// for

	*vectorCount -= 1;
	return success;

}


char* printVector(vectors* v1[], int i, errors* opRes){
	static char buffer[50];
	static char tmp1[12];
	static char tmp2[12];
	static char tmp3[12];
   	char* str = v1[i]->type->func->print(v1[i]->x);
	sprintf(tmp1, "%s", str);
	str = v1[i]->type->func->print(v1[i]->y);
	sprintf(tmp2, "%s", str);
	str = v1[i]->type->func->print(v1[i]->z);
	sprintf(tmp3, "%s", str);
	if(v1[i]->type == getIntType()) {
                sprintf(buffer, "int vector (%s, %s, %s)", tmp1, tmp2, tmp3);
		*opRes = success;
		return buffer;
        } else if(v1[i]->type == getFloatType()) {
                sprintf(buffer, "float vector (%s, %s, %s)", tmp1, tmp2, tmp3);
                *opRes = success;
		return buffer;
          }
	*opRes = failedToPrint;
	return NULL;

}

/*errors printOneVector(vectors* v1[], const int* arg){

	char* str = v1[*arg]->type->func->print(v1[*arg]->x);
                printf("(%s", str);

              str = v1[*arg]->type->func->print(v1[*arg]->y);
		printf(", %s",str);

              str = v1[*arg]->type->func->print(v1[*arg]->z);
        	printf(", %s)",str);

        return success;

}*/

int checkType(vectors* v1[], int add1, int add2, errors* opRes){

	add1 -= 1;
	add2 -= 1;
	if(v1[add1]->type->value != v1[add2]->type->value){
		*opRes = differentTypes;
		return -1; // different types
	}else if(v1[add1]->type->value == 0){
		*opRes = success;
		return 0; // int type
	}else if(v1[add1]->type->value == 1){
		*opRes = success;
		 return 1; // float type
	}else{
		*opRes = failedToCheck;
		return 400;
	}
}

errors endProgram(vectors** v1, const int* vectorCount){

	if(*vectorCount < 0){
                free(v1);
		freeINT();
		freeFLOAT();
                return success;
        }else{

		for(int i = 0; i <= *vectorCount; i++){

			freeVector(v1[i]);

		}
		free(v1);
		freeINT();
                freeFLOAT();
	}//else

	return success;
}
