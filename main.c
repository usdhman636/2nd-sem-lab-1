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
int iDotProd;
float fDotProd;
int arrCount = 10; //for malloc
vectors **vector = initiateVecArr();
char x[10], y[10], z[10];
float tempX = 0, tempY = 0, tempZ = 0;
int vectorCount = -1;
errors result = success;


while(1){
	CLEAR_SCREEN();
	printf("\n╔════════════════════════════╗");
	printf("\n║     VECTOR PROGRAM MENU    ║");
	printf("\n╠════════════════════════════╣");
	printf("\n║ 1.   Create a vector       ║");
	printf("\n║ 2.   Delete a vector       ║");
	printf("\n║ 3.   Show vector list      ║");
	printf("\n║ 4.   Add vectors together  ║");
	printf("\n║ 5.   Find dot product      ║");
	printf("\n║ 6.   Exit                  ║");
	printf("\n╚════════════════════════════╝");
	printf("\nYour choice: ");

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
		endProgram(vector, &vectorCount);
		delay(200);
		CLEAR_SCREEN();
		printf("\n╔════════════════════════════╗");
	        printf("\n║     THANK YOU FOR USING    ║");
   	        printf("\n║       VECTOR PROGRAM       ║");
	        printf("\n╠════════════════════════════╣");
	        printf("\n║                            ║");
	        printf("\n║         GOODBYE!           ║");
	        printf("\n║                            ║");
	        printf("\n╚════════════════════════════╝\n");

		return 0;
	}

	if(option == 1){
	  if(vectorCount < MAXVECTORS - 1){
		if((arrCount - vectorCount) == 1){

			vector = reallocVec(vector, &arrCount);

		}
		vectorCount += 1;
		if(createVectorScan(x, y, z, &tempX, &tempY, &tempZ) == 0){
		vector[vectorCount] = createVector(getIntType(), tempX, tempY, tempZ, &result);
		printf("\nvector successfully created!\n");
		waitForEnter();
		}else{
		 vector[vectorCount] = createVector(getFloatType(), tempX, tempY, tempZ, &result);
		 printf("\nvector successfully created!\n");
		 waitForEnter();
		 }// (else)
          }else{ printf("\nerror! max amount of vectors reached\n");// if vectorCount < MAXVECTORS
		 waitForEnter();
	   }
	}// if option = 1

	if(option == 2){

	    while(1){
		if(vectorCount < 0){
			printVectors(vector, &vectorCount);
			waitForEnter();
			break;
		}
		printVectors(vector, &vectorCount);
		printf("which vector do you want to delete:");
		while(1){
			if(!scanf("%d", &deleteOpt) || deleteOpt > vectorCount + 1 || deleteOpt < 1){
				printf("\ninvalid input, try again:");
				clear_input_buffer();
				continue;
			}else clear_input_buffer(); break;
		}
		vectorDelete(vector, &vectorCount, &deleteOpt);
		printf("\nvector successfully deleted!\n");
		waitForEnter();
		break;
	    }//while
	}// if option = 2


	if(option == 3){
		delay(200);
		CLEAR_SCREEN();
		printVectors(vector, &vectorCount);
		waitForEnter();
	}// if option = 3

	if(option == 4){

		while(1){

		if(vectorCount == MAXVECTORS - 1){
			printf("\nerror! max amount of vectors reached\n");
			waitForEnter();
			break;
		}
                if(vectorCount < 0){
                        printVectors(vector, &vectorCount);
			waitForEnter();
                        break;
                }
		if((arrCount - vectorCount) == 1){

                        vector = reallocVec(vector, &arrCount);

                }
		delay(200);
		CLEAR_SCREEN();
		printVectors(vector, &vectorCount);
		printf("choose 2 vectors to add together\n");
		while(1){

		printf("\nfirst vector:");
		if(!scanf("%d", &add1) || add1 > vectorCount + 1 || add1 < 1){
			clear_input_buffer();
			printf("\ninvalid input, try again.\n");
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
		printf("\ninvalid input, try again.\n");
		continue;
		}else{
			 clear_input_buffer();
			 break;}
		}//inner while

		if(checkType(vector, add1, add2) == -1){
			printf("\nincompatible types\n");
			waitForEnter();
			break;
		}
		vectorCount += 1;
		add1 -= 1;
		add2 -= 1;
		vector[vectorCount] = vectorAdd(vector, &add1, &add2);
		printf("\nvectors successfully summed!\n");
		waitForEnter();
		break;
		}//big while
	}// if option = 4

	if(option == 5){

	     while(1){
		if(vectorCount < 0){
                        printVectors(vector, &vectorCount);
                        waitForEnter();
			break;
                }
		delay(200);
		CLEAR_SCREEN();
                printVectors(vector, &vectorCount);
                printf("choose 2 vectors to find their dot product");
                while(1){

                printf("\n\nfirst vector:");
                if(!scanf("%d", &add1) || add1 > vectorCount + 1 || add1 < 1){
                        clear_input_buffer();
                        printf("\ninvalid input, try again.");
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
                printf("\ninvalid input, try again.\n");
                continue;
                }else{
                         clear_input_buffer();
                         break;}
                }//inner while

                if(checkType(vector, add1, add2) == -1){
                        printf("\nincompatible types\n");
                        waitForEnter();
			break;
                }
                add1 -= 1;
                add2 -= 1;
                if(vectorDotProduct(vector, &add1, &add2, &iDotProd, &fDotProd) == 0){
			printf("\n");
			printOneVector(vector, &add1);
			printf(" • ");
			printOneVector(vector, &add2);
			printf(" = %d\n", iDotProd);
			waitForEnter();
		}else {
			printf("\n");
			printOneVector(vector, &add1);
                        printf(" • ");
                        printOneVector(vector, &add2);
                        printf(" = %.4f\n", fDotProd);
			waitForEnter();
		}
                break;
                }//big while
	}
}// main while loop

return 0;
}// int main()
