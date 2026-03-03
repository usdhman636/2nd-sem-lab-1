#include <stdlib.h>
#include "int.h"

static itype* INT_INPUT_TYPE = NULL;

int intAdd(const void* arg1, const void* arg2, void* result){

	*(int*)result = *(int*)arg1 + *(int*)arg2;
	return 0;
}
int intDotProduct(const void* arg1, const void* arg2, void* result){

	*(int*)result = *(int*)arg1 * *(int*)arg2;
        return 0;
}
int intPrint(const void* result){

	return *(int*)result;
}

itype* getIntType(){

	if(INT_INPUT_TYPE == NULL){
		INT_INPUT_TYPE = malloc(sizeof(itype))
		if(INT_INPUT_TYPE == NULL) return -1;
		INT_INPUT_TYPE->size = sizeof(int);
        	INT_INPUT_TYPE->add = intAdd;
        	INT_INPUT_TYPE->dotProduct = intDotProduct;
        	INT_INPUT_TYPE->print = intPrint;
	}
   return INT_INPUT_TYPE;
}
