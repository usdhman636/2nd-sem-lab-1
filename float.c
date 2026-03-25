#include <stdlib.h>
#include "float.h"

static itype* FLOAT_INPUT_TYPE = NULL;

int floatAdd(const void* arg1, const void* arg2, void* result){

        *(float*)result = *(float*)arg1 + *(float*)arg2;
        return 0;
}
int floatDotProduct(const void* arg1, const void* arg2, void* result){

        *(float*)result = *(float*)arg1 * *(float*)arg2;
        return 0;
}
char* floatPrint(const void* result){

        static char buffer2[32];  // Static buffer to hold the string
        sprintf(buffer2, "%.3f", *(float*)result);
        return buffer2;
}

itype* getFloatType(){

        if(FLOAT_INPUT_TYPE == NULL){
                FLOAT_INPUT_TYPE = malloc(sizeof(itype));
                if(FLOAT_INPUT_TYPE == NULL) exit(1);
                FLOAT_INPUT_TYPE->func = malloc(sizeof(itypeFunc));
                if(FLOAT_INPUT_TYPE->func == NULL) exit(1);
                FLOAT_INPUT_TYPE->size = sizeof(float);
		FLOAT_INPUT_TYPE->value = 1;
                FLOAT_INPUT_TYPE->func->add = floatAdd;
                FLOAT_INPUT_TYPE->func->dotProduct = floatDotProduct;
                FLOAT_INPUT_TYPE->func->print = floatPrint;
        }
   return FLOAT_INPUT_TYPE;
}

int freeFLOAT(){

	while(1){
	if(FLOAT_INPUT_TYPE == NULL) break;
	free(FLOAT_INPUT_TYPE->func);
	free(FLOAT_INPUT_TYPE);
	return 0;
	}
}
