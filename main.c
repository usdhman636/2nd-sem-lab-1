#include <stdio.h>
#include "int.h"
#include "float.h"
#include "vector.h"
#include "errors.h"
#include "itype.h"

#define MAXOPTIONS = 6
#define MAXVECTORS = 50

int main()
{

int option = 0;
vectors vector[MAXVECTORS];
float tempX = 0, tempY = 0, tempZ = 0;
int vectorCount = 0;
errors result = ok;

printf("welcome to my vectors programe\nchoose an option\n");
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
		printf("\ngoodbye");
		return 0;
	}

	if(option == 1){
	  if(vectorCount < MAXVECTORS){
		printf("\nenter x value:");
		while(1){
			if(!scanf("%f",&tempX)){
                	clear_input_buffer();
                	printf("\ninvalid input, try again:");
                	continue;
                	}
        		clear_input_buffer();
        		break;
		}
		printf("\nenter y value:");
                while(1){
                        if(!scanf("%f",&tempZ)){
                        clear_input_buffer();
                        printf("\ninvalid input, try ag>
                        continue;
                        }
                        clear_input_buffer();
                        break;
                }
		printf("\nenter z value:");
                while(1){
                        if(!scanf("%f",&tempZ)){
                        clear_input_buffer();
                        printf("\ninvalid input, try ag>
                        continue;
                        }
                        clear_input_buffer();
                        break;
                }
		if(checkType(&tempX, &tempY, &tempZ) == 0){
		vector[vectorCount] = creatVector(getIntType(), &tempX, &tempY, &tempZ, &result);
		vectorCount += 1;

		}else{
		 vector[vectorCount] = creatVector(getFloatType(), &tempX, &tempY, &tempZ, &result);
		 vectorCount += 1; 
		 }// else
          }else printf("max amount of vectors reached");// if vectorCount < MAXVECTORS
	}// if option = 1


}// main while loop

return 0;
}// int main()
