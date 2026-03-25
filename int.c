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
char* intPrint(const void* result){

	static char buffer[32];  // Static buffer to hold the string
    	sprintf(buffer, "%d", *(int*)result);
    	return buffer;

}

itype* getIntType(){

	if(INT_INPUT_TYPE == NULL){
		INT_INPUT_TYPE = malloc(sizeof(itype));
		if(INT_INPUT_TYPE == NULL) exit(1);
		INT_INPUT_TYPE->func = malloc(sizeof(itypeFunc));
		if(INT_INPUT_TYPE->func == NULL) exit(1);
		INT_INPUT_TYPE->size = sizeof(int);
		INT_INPUT_TYPE->value = 0;
        	INT_INPUT_TYPE->func->add = intAdd;
        	INT_INPUT_TYPE->func->dotProduct = intDotProduct;
        	INT_INPUT_TYPE->func->print = intPrint;
	}
   return INT_INPUT_TYPE;
}

int freeINT(){
	while(1){
	if(INT_INPUT_TYPE == NULL) break;
	free(INT_INPUT_TYPE->func);
	free(INT_INPUT_TYPE);
	return 0;
	}
}
