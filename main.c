#include <stdio.h>
#include "int.h"
#include "float.h"
#include "vector.h"
#include "errors.h"
#include "itype.h"
#include "io.h"

#define MAXOPTIONS  7
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
int testTrigger = 1;


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
	printf("\n║ 6.   Test program          ║");
	printf("\n║ 7.   Exit                  ║");
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
	if(option != 6){testTrigger = -1;}
	clear_input_buffer();
	break;
	}

	if(option == MAXOPTIONS){
		endProgram(vector, &vectorCount);
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
		printOneVector(vector, &vectorCount);
		printf("\n");
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
                        printf(" = %.3f\n", fDotProd);
			waitForEnter();
		}
                break;
                }//big while
	}

	if(option == 6){
		if(testTrigger == 1){
			CLEAR_SCREEN();
			printf("\ncreating vectors...\n");
			delay(1500);
			vectorCount +=1;
			vector[0] = createVector(getIntType(), 5, 3, 7, &result);
			printf("\n1st vector successfully created!\n");
			printOneVector(vector, &(int){0}); printf("\n");
			delay(1500);
			vectorCount +=1;
			vector[1] = createVector(getFloatType(), 9.35, 1.18, 6, &result);
			printf("\n2nd vector successfully created!\n");
			printOneVector(vector, &(int){1}); printf("\n");
			vectorCount +=1;
			vector[2] = createVector(getIntType(), 12, 4, 8, &result);
			delay(1500);
			printf("\n3rd vector successfully created!\n");
			printOneVector(vector, &(int){2}); printf("\n");
			delay(1500);
			printVectors(vector, &vectorCount);

			delay(2000);
			printf("\nadding vector 1 and 2\n");
			delay(1500);
			if(checkType(vector, 1, 2) == -1){
                        	printf("\nincompatible types\n");
			}
			delay(2000);
			printf("\nadding vector 1 and 3\n");
			vectorCount +=1;
			delay(1500);
			vector[vectorCount] = vectorAdd(vector,&(int){0}, &(int){2});
                	printf("\nvectors successfully summed!\n");
			delay(1500);
			printVectors(vector, &vectorCount);
			delay(3000);

			printf("\nfinding dot product of vector 3 and 4\n");
			fflush(stdout);
			delay(1500);
			vectorDotProduct(vector, &(int){2}, &(int){3}, &iDotProd, &fDotProd);
                        printf("\n");
                        printOneVector(vector, &(int){2});
			fflush(stdout);
			delay(1000);
                        printf(" • ");
			fflush(stdout);
			delay(1000);
                        printOneVector(vector, &(int){3});
			fflush(stdout);
			delay(1000);
                        printf(" = %d\n", iDotProd);
			delay(3000);

			printf("\ndeleting vector 2...\n");
			delay(2000);
			vectorDelete(vector, &vectorCount, &(int){2});
                	printf("\nvector successfully deleted!\n");
			delay(2000);
			printVectors(vector, &vectorCount);

			//freeing vectors
			vectorDelete(vector, &vectorCount, &(int){3});
			vectorDelete(vector, &vectorCount, &(int){2});
			vectorDelete(vector, &vectorCount, &(int){1});


			testTrigger = -1;
			waitForEnter();
			continue;
		}//testTrigger
		else{

			printf("\nTest program can only be run once\nand only at the start\n");
			waitForEnter();
			continue;

		}
	}
}// main while loop

return 0;
}// int main()
