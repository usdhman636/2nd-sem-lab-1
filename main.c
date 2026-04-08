#include <stdio.h>
#include <windows.h>

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
   SetConsoleOutputCP(CP_UTF8);
   SetConsoleCP(CP_UTF8);

int option = 0, deleteOpt = 0;
int add1 = 0, add2 = 0;
int iDotProd;
float fDotProd;
int arrCount = 10; //for malloc
errors opRes = success;
vectors **vector = initiateVecArr(&opRes);
char x[10], y[10], z[10];
float tempX = 0, tempY = 0, tempZ = 0;
int vectorCount = -1;
int testTrigger = 1;

while(1){
	CLEAR_SCREEN();
	printf("\n╔════════════════════════════╗");
	printf("\n║     VECTOR PROGRAM MENU    ║");
	printf("\n╠════════════════════════════╣");
	printf("\n║ 1.   Создать вектор        ║");
	printf("\n║ 2.   Удалить вектор        ║");
	printf("\n║ 3.   Список векторов       ║");
	printf("\n║ 4.   Сложить векторы       ║");
	printf("\n║ 5.   Скалярное произведение║");
	printf("\n║ 6.   Тест программы        ║");
	printf("\n║ 7.   Выход                 ║");
	printf("\n╚════════════════════════════╝");
	printf("\nваш выбор: ");

	while(1){
		if(!scanf("%d",&option)){
		clear_input_buffer();
		printf("\nНеверный ввод, попробуйте еще раз:");
		continue;
		}
		if(option < 1 || option > MAXOPTIONS){
		clear_input_buffer();
		printf("\nНеверный ввод, попробуйте еще раз:");
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

			vector = reallocVec(vector, &arrCount, &opRes);

		}
		vectorCount += 1;
		    while (1) {
        printf("\nВведите x: ");

        if (scanf("%7s", x) != 1) {
            clear_input_buffer();
            printf("\nНеверный ввод, попробуйте еще раз.\n");
            continue;
        }

        clear_input_buffer();

        if(inputCheck(x) == 1){
		printf("\nНеверный номер, попробуйте еще раз.\n");
		continue;
	}else break;
    }

    while (1) {
        printf("\nВведите y: ");

        if (scanf("%7s", y) != 1) {
            clear_input_buffer();
            printf("\nНеверный ввод, попробуйте еще раз.\n");
            continue;
        }

        clear_input_buffer();

	if(inputCheck(y) == 1){
                printf("\nНеверный номер, попробуйте еще раз.\n");
                continue;
        }else break;
    }

    while (1) {
        printf("\nВведите z: ");

        if (scanf("%7s", z) != 1) {
            clear_input_buffer();
            printf("\nНеверный ввод, попробуйте еще раз.\n");
            continue;
        }

        clear_input_buffer();

	if(inputCheck(z) == 1){
                printf("\nНеверный номер, попробуйте еще раз.\n");
                continue;
        }else break;
    }

		if(typeAssign(x, y, z, &tempX, &tempY, &tempZ) == 0){
		vector[vectorCount] = createVector(getIntType(), tempX, tempY, tempZ, &opRes);
		printf("\nВектор успешно создан!\n");
		waitForEnter();
		}else{
		 vector[vectorCount] = createVector(getFloatType(), tempX, tempY, tempZ, &opRes);
		 printf("\nВектор успешно создан!\n");
		 waitForEnter();
		 }// (else)
          }else{ printf("\nОшибка! Достигнуто максимальное количество векторов.\n");// if vectorCount < MAXVECTORS
		 waitForEnter();
	   }
	}// if option = 1

	if(option == 2){

	    while(1){
		if(vectorCount < 0){
			printf("\nНет доступных векторов\n");
			waitForEnter();
			break;
		}
		for(int i = 0; i <= vectorCount; i++){
                printf("\n%d-%s\n",i+1,printVector(vector, i, &opRes));
                }
		printf("\nКакой вектор вы хотите удалить:");
		while(1){
			if(!scanf("%d", &deleteOpt) || deleteOpt > vectorCount + 1 || deleteOpt < 1){
				printf("\nНеверный ввод, попробуйте еще раз:");
				clear_input_buffer();
				continue;
			}else clear_input_buffer(); break;
		}
		vectorDelete(vector, &vectorCount, &deleteOpt);
		printf("\nВектор успешно удалён!\n");
		waitForEnter();
		break;
	    }//while
	}// if option = 2


	if(option == 3){
		CLEAR_SCREEN();
		if(vectorCount < 0){
		printf("\nНет доступных векторов\n");
		}else{
			for(int i = 0; i <= vectorCount; i++){
			printf("\n%d-%s\n",i+1,printVector(vector, i, &opRes));
			}
		}
		waitForEnter();
	}// if option = 3

	if(option == 4){

		while(1){

		if(vectorCount == MAXVECTORS - 1){
			printf("\nОшибка! Достигнуто максимальное количество векторов.\n");
			waitForEnter();
			break;
		}
                if(vectorCount < 0){
                        printf("\nНет доступных векторов\n");
			waitForEnter();
                        break;
                }
		if((arrCount - vectorCount) == 1){

                        vector = reallocVec(vector, &arrCount, &opRes);

                }
		CLEAR_SCREEN();
                for(int i = 0; i <= vectorCount; i++){
                printf("\n%d-%s\n",i+1,printVector(vector, i, &opRes));
                }
		printf("\nВыберите 2 вектора для сложения.\n");
		while(1){

		printf("\nпервый вектор:");
		if(!scanf("%d", &add1) || add1 > vectorCount + 1 || add1 < 1){
			clear_input_buffer();
			printf("\nНеверный ввод, попробуйте еще раз.\n");
			continue;
		}else{
			 clear_input_buffer();
			 break;
		}
		}//inner while

		while(1){
		printf("\nвторой вектор:");
		if(!scanf("%d", &add2) || add2 > vectorCount + 1 || add2 < 1){

		clear_input_buffer();
		printf("\nНеверный ввод, попробуйте еще раз.\n");
		continue;
		}else{
			 clear_input_buffer();
			 break;}
		}//inner while

		if(checkType(vector, add1, add2, &opRes) == -1){
			printf("\nнесовместимые типы\n");
			waitForEnter();
			break;
		}
		vectorCount += 1;
		add1 -= 1;
		add2 -= 1;
		vector[vectorCount] = vectorAdd(vector, &add1, &add2, &opRes);
		printf("\nВекторы успешно сложены!!\n");
		printf("\n%s",printVector(vector, vectorCount, &opRes));
		printf("\n");
		waitForEnter();
		break;
		}//big while
	}// if option = 4

	if(option == 5){

	     while(1){
		if(vectorCount < 0){
                        printf("\nНет доступных векторов\n");
                        waitForEnter();
			break;
                }
		CLEAR_SCREEN();
                for(int i = 0; i <= vectorCount; i++){
                printf("\n%d-%s\n",i+1,printVector(vector, i, &opRes));
                }
                printf("\nВыберите 2 вектора, чтобы найти их скалярное произведение.");
                while(1){

                printf("\n\nпервый вектор:");
                if(!scanf("%d", &add1) || add1 > vectorCount + 1 || add1 < 1){
                        clear_input_buffer();
                        printf("\nНеверный ввод, попробуйте еще раз.");
                        continue;
                }else{
                         clear_input_buffer();
                         break;
                }
                }//inner while

                while(1){
                printf("\nвторой вектор:");
                if(!scanf("%d", &add2) || add2 > vectorCount + 1 || add2 < 1){

                clear_input_buffer();
                printf("\nНеверный ввод, попробуйте еще раз.\n");
                continue;
                }else{
                         clear_input_buffer();
                         break;}
                }//inner while

                if(checkType(vector, add1, add2, &opRes) == -1){
                        printf("\nнесовместимые типы\n");
                        waitForEnter();
			break;
                }
                add1 -= 1;
                add2 -= 1;
                if(vectorDotProduct(vector, &add1, &add2, &iDotProd, &fDotProd, &opRes) == 0){
			printf("\n");
			printf("%s",printVector(vector, add1, &opRes));
			printf(" • ");
			printf("%s",printVector(vector, add2, &opRes));
			printf(" = %d\n", iDotProd);
			waitForEnter();
		}else {
			printf("\n");
			printf("%s",printVector(vector, add1, &opRes));
                        printf(" • ");
                        printf("%s",printVector(vector, add2, &opRes));
                        printf(" = %.3f\n", fDotProd);
			waitForEnter();
		}
                break;
                }//big while
	}

	if(option == 6){
		if(testTrigger == 1){
			CLEAR_SCREEN();
			// creating vectors tests
			// if input is not a number for each variable (x y z)
			vectorCount += 1;
                    while (1) {
        printf("\nВведите x: ");

        if (sscanf("x", "%9s", x) != 1) {
            //clear_input_buffer();
            //printf("\nНеверный ввод, попробуйте еще раз.\n");
            //continue;
        }

        //clear_input_buffer();

        if(inputCheck(x) == 1){
                printf("\nНеверный номер, попробуйте еще раз.\n");
                sscanf("8", "%9s", x);
        }else break;
	break;
    }

    while (1) {
        printf("\nВведите y: ");

        if (sscanf("y", "%9s", y) != 1) {
            //clear_input_buffer();
            //printf("\nНеверный ввод, попробуйте еще раз.\n");
            //continue;
        }

        //clear_input_buffer();

        if(inputCheck(y) == 1){
                printf("\nНеверный номер, попробуйте еще раз.\n");
                sscanf("3", "%9s", y);
        }else break;
	break;
    }

    while (1) {
        printf("\nВведите z: ");

        if (sscanf("z", "%9s", z) != 1) {
            //clear_input_buffer();
            //printf("\nНеверный ввод, попробуйте еще раз.\n");
            //continue;
        }

        //clear_input_buffer();

        if(inputCheck(z) == 1){
                printf("\nНеверный номер, попробуйте еще раз.\n");
                sscanf("2.5", "%9s", z);
        }else break;
	break;
    }
		if(typeAssign(x, y, z, &tempX, &tempY, &tempZ) == 0){
                vector[vectorCount] = createVector(getIntType(), tempX, tempY, tempZ, &opRes);
                printf("\nВектор успешно создан!\n");
		printf("\n%d-%s\n",vectorCount+1,printVector(vector, vectorCount, &opRes));
                }else{
                 vector[vectorCount] = createVector(getFloatType(), tempX, tempY, tempZ, &opRes);
                 printf("\nВектор успешно создан!\n");
                 }// (else)

			// -------1-------

		// создать ноливой вектор int и float
		vectorCount += 1;
		vector[vectorCount] = createVector(getIntType(), (float){0}, (float){0}, (float){0}, &opRes);
                printf("\nВектор успешно создан!\n");
		printf("\n%d-%s\n",vectorCount+1,printVector(vector, vectorCount, &opRes));

		vectorCount += 1;
                vector[vectorCount] = createVector(getFloatType(), (float){0}, (float){0}, (float){0}, &opRes);
                printf("\nВектор успешно создан!\n");
                printf("\n%d-%s\n",vectorCount+1,printVector(vector, vectorCount, &opRes));

		// создать отрицатильные векторы

		vectorCount += 1;
                vector[vectorCount] = createVector(getIntType(), (float){-6}, (float){-8}, (float){-5}, &opRes);
                printf("\nВектор успешно создан!\n");
                printf("\n%d-%s\n",vectorCount+1,printVector(vector, vectorCount, &opRes));

		vectorCount += 1;
                vector[vectorCount] = createVector(getFloatType(), (float){-1.948}, (float){-91.59}, (float){-8.37}, &opRes);
                printf("\nВектор успешно создан!\n");
                printf("\n%d-%s\n",vectorCount+1,printVector(vector, vectorCount, &opRes));

		//создать бодьшие векторы
		 vectorCount += 1;
                    while (1) {
        printf("\nВведите x: ");

        if (sscanf("999999999999999", "%7s", x) != 1) {
            //clear_input_buffer();
            //printf("\nНеверный ввод, попробуйте еще раз.\n");
            //continue;
        }

        //clear_input_buffer();

        if(inputCheck(x) == 1){
                printf("\nНеверный номер, попробуйте еще раз.\n");
                sscanf("8", "%9s", x);
        }else break;
        break;
    }

    while (1) {
        printf("\nВведите y: ");

        if (sscanf("-999999999999999", "%7s", y) != 1) {
            //clear_input_buffer();
            //printf("\nНеверный ввод, попробуйте еще раз.\n");
            //continue;
        }

        //clear_input_buffer();

        if(inputCheck(y) == 1){
                printf("\nНеверный номер, попробуйте еще раз.\n");
                sscanf("3", "%9s", y);
        }else break;
        break;
    }

    while (1) {
        printf("\nВведите z: ");

        if (sscanf("999999999999999.9999999", "%7s", z) != 1) {
            //clear_input_buffer();
            //printf("\nНеверный ввод, попробуйте еще раз.\n");
            //continue;
        }

        //clear_input_buffer();

        if(inputCheck(z) == 1){
                printf("\nНеверный номер, попробуйте еще раз.\n");
                sscanf("2", "%9s", z);
        }else break;
        break;
    }
                if(typeAssign(x, y, z, &tempX, &tempY, &tempZ) == 0){
                vector[vectorCount] = createVector(getIntType(), tempX, tempY, tempZ, &opRes);
                printf("\nВектор успешно создан!\n");
                printf("\n%d-%s\n",vectorCount+1,printVector(vector, vectorCount, &opRes));
                }else{
                 vector[vectorCount] = createVector(getFloatType(), tempX, tempY, tempZ, &opRes);
                 printf("\nВектор успешно создан!\n");
                 }// (else)

		//создадть вектор когда reached MAXVECTORS
		for(int i = 6; i < (MAXVECTORS); i++){

			vectorCount += 1;
			vector[vectorCount] = createVector(getIntType(), (float){0}, (float){0}, (float){0}, &opRes);
                	printf("\nВектор успешно создан!\n");
                	printf("\n%d-%s\n",vectorCount+1,printVector(vector, vectorCount, &opRes));

		}
		if(vectorCount < MAXVECTORS - 1){
                if((arrCount - vectorCount) == 1){

                        vector = reallocVec(vector, &arrCount, &opRes);

                }
                vectorCount += 1;
                    while (1) {
        printf("\nВведите x: ");

        if (scanf("%7s", x) != 1) {
            clear_input_buffer();
            printf("\nНеверный ввод, попробуйте еще раз.\n");
            continue;
        }

        clear_input_buffer();

        if(inputCheck(x) == 1){
                printf("\nНеверный номер, попробуйте еще раз.\n");
                continue;
        }else break;
    }

    while (1) {
        printf("\nВведите y: ");

        if (scanf("%7s", y) != 1) {
            clear_input_buffer();
            printf("\nНеверный ввод, попробуйте еще раз.\n");
            continue;
        }

        clear_input_buffer();

        if(inputCheck(y) == 1){
                printf("\nНеверный номер, попробуйте еще раз.\n");
                continue;
        }else break;
    }

    while (1) {
        printf("\nВведите z: ");

        if (scanf("%7s", z) != 1) {
            clear_input_buffer();
            printf("\nНеверный ввод, попробуйте еще раз.\n");
            continue;
        }

        clear_input_buffer();

        if(inputCheck(z) == 1){
                printf("\nНеверный номер, попробуйте еще раз.\n");
                continue;
        }else break;
    }

                if(typeAssign(x, y, z, &tempX, &tempY, &tempZ) == 0){
                vector[vectorCount] = createVector(getIntType(), tempX, tempY, tempZ, &opRes);
                printf("\nВектор успешно создан!\n");
                waitForEnter();
                }else{
                 vector[vectorCount] = createVector(getFloatType(), tempX, tempY, tempZ, &opRes);
                 printf("\nВектор успешно создан!\n");
                 waitForEnter();
                 }// (else)
          }else{ printf("\nОшибка! Достигнуто максимальное количество векторов.\n");// if vectorCount < MAXVECTORS
           }
	 waitForEnter();

	// show list if maxvectors is resched
	if(vectorCount < 0){
                printf("\nНет доступных векторов\n");
                }else{
                        for(int i = 0; i <= vectorCount; i++){
                        printf("\n%d-%s\n",i+1,printVector(vector, i, &opRes));
                        }

	//delete out of bounds then delete last vector then delete first vector
	while(1){
                        if(!sscanf("51", "%d", &deleteOpt) || deleteOpt > vectorCount + 1 || deleteOpt < 1){
                                printf("\nНеверный ввод, попробуйте еще раз:");
                                deleteOpt = 50;
				waitForEnter();
                                break;
                        }else clear_input_buffer(); break;
                }
                vectorDelete(vector, &vectorCount, &deleteOpt);
                printf("\nВектор успешно удалён!\n");
                for(int i = 0; i <= vectorCount; i++){
                        printf("\n%d-%s\n",i+1,printVector(vector, i, &opRes));
                        }
		waitForEnter();
		CLEAR_SCREEN();


			deleteOpt = 1;
			vectorDelete(vector, &vectorCount, &deleteOpt);
			printf("\nВектор успешно удалён!\n");
                	for(int i = 0; i <= vectorCount; i++){
                        	printf("\n%d-%s\n",i+1,printVector(vector, i, &opRes));
                        }
			}
			waitForEnter();
			CLEAR_SCREEN();
			//sum 2 vectors if MAXVECTORS is reached
			vectorCount += 1;
                	vector[vectorCount] = createVector(getIntType(), (float){0}, (float){0}, (float){0}, &opRes);
			vectorCount += 1;
                	vector[vectorCount] = createVector(getIntType(), (float){0}, (float){0}, (float){0}, &opRes);
		        if(vectorCount == MAXVECTORS - 1){
        	                printf("\nОшибка! Достигнуто максимальное количество векторов.\n");
                	}

			//dot prod if maxvectors reached
			add1 = 2;
			add2 = 2;
			if(vectorDotProduct(vector, &add1, &add2, &iDotProd, &fDotProd, &opRes) == 0){
                        	printf("\n");
                        	printf("%s",printVector(vector, add1, &opRes));
                        	printf(" • ");
                        	printf("%s",printVector(vector, add2, &opRes));
                        	printf(" = %d\n", iDotProd);
                	}

			//show list if empty delete if empty sum of empty dot prod if empty
			for(int i = MAXVECTORS; i > 0; i--){
				vectorDelete(vector, &vectorCount, &i);
			}
			if(vectorCount < 0){
		                printf("\nНет доступных векторов\n");}
			if(vectorCount < 0){
                		printf("\nНет доступных векторов\n");}
			if(vectorCount < 0){
               			 printf("\nНет доступных векторов\n");}
			if(vectorCount < 0){
                		printf("\nНет доступных векторов\n");}

			//add vectors together
			//if only 1 vector in list
			vectorCount += 1;
                	vector[vectorCount] = createVector(getIntType(), (float){-6}, (float){-8}, (float){-5}, &opRes);
                	printf("\nВектор успешно создан!\n");
                	printf("\n%d-%s\n",vectorCount+1,printVector(vector, vectorCount, &opRes));

			vectorCount += 1;
	                add1 = 0;
	                add2 = 0;
	                vector[vectorCount] = vectorAdd(vector, &add1, &add2, &opRes);
	                printf("\nВекторы успешно сложены!!\n");
	                printf("\n%s\n",printVector(vector, vectorCount, &opRes));

			// float + float
			vectorCount += 1;
	                vector[vectorCount] = createVector(getFloatType(), (float){6.28}, (float){-91.379}, (float){16}, &opRes);
	                printf("\nВектор успешно создан!\n");
	                printf("\n%d-%s\n",vectorCount+1,printVector(vector, vectorCount, &opRes));

			vectorCount += 1;
	                add1 = 2;
	                add2 = 2;
	                vector[vectorCount] = vectorAdd(vector, &add1, &add2, &opRes);
	                printf("\nВекторы успешно сложены!!\n");
	                printf("\n%s\n",printVector(vector, vectorCount, &opRes));

			//int + float
                        add1 = 2;
                        add2 = 3;
			if(checkType(vector, add1, add2, &opRes) == -1){
                        printf("\nнесовместимые типы\n");
			}
			//float + int
                        add1 = 3;
                        add2 = 1;
			if(checkType(vector, add1, add2, &opRes) == -1){
                        printf("\nнесовместимые типы\n");
			}

			//dot prod
			//if 1 vector
			deleteOpt = 3;
			vectorDelete(vector, &vectorCount, &deleteOpt);
			deleteOpt = 2;
			vectorDelete(vector, &vectorCount, &deleteOpt);

			add1 = 0;
                	add2 = 0;
                if(vectorDotProduct(vector, &add1, &add2, &iDotProd, &fDotProd, &opRes) == 0){
                        printf("\n");
                        printf("%s",printVector(vector, add1, &opRes));
                        printf(" • ");
                        printf("%s",printVector(vector, add2, &opRes));
                        printf(" = %d\n", iDotProd);
                        //waitForEnter();
                }else {
                        printf("\n");
                        printf("%s",printVector(vector, add1, &opRes));
                        printf(" • ");
                        printf("%s",printVector(vector, add2, &opRes));
                        printf(" = %.3f\n", fDotProd);
                        //waitForEnter();
                }

			// if float * float
			vectorCount += 1;
	                vector[vectorCount] = createVector(getFloatType(), (float){-6.83}, (float){28.19}, (float){26.194}, &opRes);
	                printf("\nВектор успешно создан!\n");
	                printf("\n%d-%s\n",vectorCount+1,printVector(vector, vectorCount, &opRes));

			vectorCount += 1;
                        vector[vectorCount] = createVector(getFloatType(), (float){-829.3}, (float){7.19}, (float){81.4}, &opRes);
                        printf("\nВектор успешно создан!\n");
                        printf("\n%d-%s\n",vectorCount+1,printVector(vector, vectorCount, &opRes));

			add1 = 1;
                	add2 = 2;
                if(vectorDotProduct(vector, &add1, &add2, &iDotProd, &fDotProd, &opRes) == 0){
                        printf("\n");
                        printf("%s",printVector(vector, add1, &opRes));
                        printf(" • ");
                        printf("%s",printVector(vector, add2, &opRes));
                        printf(" = %d\n", iDotProd);
                        
                }else {
                        printf("\n");
                        printf("%s",printVector(vector, add1, &opRes));
                        printf(" • ");
                        printf("%s",printVector(vector, add2, &opRes));
                        printf(" = %.3f\n", fDotProd);
                       
                }

			//if int • float
			add1 = 1;
			add2 = 2;
			  if(checkType(vector, add1, add2, &opRes) == -1){
                        	printf("\nнесовместимые типы\n");
			  }

			add1 = 3;
			add2 = 1;
			  if(checkType(vector, add1, add2, &opRes) == -1){
                        	printf("\nнесовместимые типы\n");
			  }

			//deleting tests
			for(int i = 4; i > 0; i--){
			vectorDelete(vector, &vectorCount, &i);
			}


			testTrigger = -1;
			waitForEnter();
			continue;
		}//testTrigger
		else{

			printf("\nтест программы может быть запущен только один раз\nи только в начале\n");
			waitForEnter();
			continue;

		}
	}
}// main while loop

return 0;
}// int main()
