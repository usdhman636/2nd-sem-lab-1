#include <stdio.h>
#include "int.h"
#include "float.h"
#include "vector.h"
#include "errors.h"
#include "itype.h"
#include "io.h"

#define MAXOPTIONS  6
#define MAXVECTORS  50

int main()
{

int option = 0;
vectors *vector[MAXVECTORS];
char x[10], y[10], z[10];
float tempX = 0, tempY = 0, tempZ = 0;
int vectorCount = 0;
errors result = success;

printf("welcome to my vectors program\nchoose an option\n");
while(1){

	printf("1-creat a vector");
	printf("\n2-delete a vector");
	printf("\n3-show vector lists");
	printf("\n4-add vectors together");
	printf("\n5-find dotproduct");
	printf("\n6-exit\n:");

	while(1){
		if(!scanf("%d",&option)){
		clear_input_buffer();
		printf("\ninvalid option, try again:");
		continue;
		}
		if(option < 1 || option > MAXOPTIONS){
		clear_input_buffer();
		printf("\ninvalid option, try again:");
		continue;
		}
	clear_input_buffer();
	break;
	}

	if(option == MAXOPTIONS){
		printf("\ngoodbye\n");
		return 0;
	}

	if(option == 1){
	  if(vectorCount < MAXVECTORS){
		if(createVectorScan(x, y, z, &tempX, &tempY, &tempZ) == 0){
		vector[vectorCount] = createVector(getIntType(), &tempX, &tempY, &tempZ, &result);
		vectorCount += 1;
		}else{
		 vector[vectorCount] = createVector(getFloatType(), &tempX, &tempY, &tempZ, &result);
		 vectorCount += 1;
		 }// else
          }else printf("max amount of vectors reached");// if vectorCount < MAXVECTORS
	}// if option = 1


}// main while loop

return 0;
}// int main()
