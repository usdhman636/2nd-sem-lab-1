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

int option = 0, deleteOpt = 0;
int add1 = 0, add2 = 0;
vectors *vector[MAXVECTORS];
char x[10], y[10], z[10];
float tempX = 0, tempY = 0, tempZ = 0;
int vectorCount = -1;
errors result = success;


printf("welcome to my vectors program\nchoose an option\n");
while(1){

	printf("\n1-creat a vector");
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
	  if(vectorCount < MAXVECTORS - 1){
		vectorCount += 1;
		if(createVectorScan(x, y, z, &tempX, &tempY, &tempZ) == 0){
		vector[vectorCount] = createVector(getIntType(), tempX, tempY, tempZ, &result);
		}else{
		 vector[vectorCount] = createVector(getFloatType(), tempX, tempY, tempZ, &result);
		 printf("\nvector successfuly created!\n");
		 }// (else)
          }else printf("\nmax amount of vectors reached\n");// if vectorCount < MAXVECTORS
	}// if option = 1

	if(option == 2){

	    while(1){
		if(vectorCount < 0){
			printVectors(vector, &vectorCount);
			break;
		}
		printVectors(vector, &vectorCount);
		printf("which vector do you want to delete:");
		while(1){
			if(!scanf("%d", &deleteOpt) || deleteOpt > vectorCount + 1 || deleteOpt < 1){
				printf("invalid input, try again:");
				clear_input_buffer();
				continue;
			}else clear_input_buffer(); break;
		}
		vectorDelete(vector, &vectorCount, &deleteOpt);
		printf("\nvector successfuly deleted!\n");
		break;
	    }//while
	}// if option = 2


	if(option == 3){

		printVectors(vector, &vectorCount);
	}// if option = 3

	if(option == 4){

		while(1){
                if(vectorCount < 0){
                        printVectors(vector, &vectorCount);
                        break;
                }
		printVectors(vector, &vectorCount);
		printf("\nchoose 2 vectors to add together");
		while(1){

		printf("\nfirst vector:");
		if(!scanf("%d", &add1) || add1 > vectorCount + 1 || add1 < 1){
			clear_input_buffer();
			printf("\ninvalid input, try again");
			continue;
		}else{
			 clear_input_buffer();
			 break;
		}
		}//inner while

		while(1){
		printf("\nsecond vector:");
		if(!scanf("%d", &add2) || add2 > vectorCount + 1 || add2 < 1){

		clear_input_buffer();
		printf("\ninvalid input, try again");
		continue;
		}else{
			 clear_input_buffer();
			 break;}
		}//inner while

		if(checkType(vector, add1, add2) == -1){
			printf("\nincompatible types\n");
			break;
		}
		vectorCount += 1;
		add1 -= 1;
		add2 -= 1;
		vector[vectorCount] = vectorAdd(vector, &add1, &add2);
		printf("\nvectors successfuly summed!\n");
		break;
		}//big while
	}// if option = 4

}// main while loop

return 0;
}// int main()
