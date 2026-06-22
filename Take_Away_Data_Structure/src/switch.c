#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "/home/akash/Take_Away_Data_Structure/170868_Akash_Data_Structure_Linked_List_TakeAway_T011/include/header.h"\

int insert_mat();
void  insertatbegin(struct matrix* , int row, int column , double value);
void ex1() {
	int8_t choice;
	printf("\n===== linked list take away exercise =====\n");
	printf("1.matrix init\n");
	printf("2.insert element in matrix\n");
	printf("3.deuplicate element\n");
	printf("4.resize matrix\n");
	printf("5.transpose of the matrix\n");
	printf("0. back\n");
	printf("enter choice: ");

	if(scanf("%hhd", &choice) != 1){
		while(getchar() != '\n');
		printf("Invalid input\n");
		return;
	}
	switch(choice){
		case 1: initmat(); break;
		case 2: insert_mat(); break;
		case 3: duplicate(); break;
		case 4: resize_mat(); break;
		case 5: transpose_mat(); break;
		case 0: return;
		default:printf("Invalid choice\n");
	}
}
void ex2() {
	int8_t choice;
	printf("\n===== binary tree take away exercise =====\n");
	printf("1.game\n");
	printf("0. back\n");
	printf("enter choice: ");

	if(scanf("%hhd", &choice) != 1){
		while(getchar() != '\n');
		printf("Invalid input\n");
		return;
	}
	switch(choice){
		case 1: game(); break;
		case 0: return;
		default:printf("Invalid choice\n");
	}
}
void ex3(){
	int8_t choice;
	printf("\n======Queue take away excercise======\n");
	printf("1.patient management \n");
	printf("0. back\n");
	printf("enter choice: ");

	if(scanf("%hhd", &choice) != 1){
                while(getchar() != '\n');
                printf("Invalid input\n");
                return;
        }
	switch(choice){
                case 1:  patient_(); break;
                case 0: return;
                default:printf("Invalid choice\n");
        }
}
int32_t switch1() {
	int8_t module;

	while(1){
		printf("\n===== MAIN MENU =====\n");
		printf("1. linked list take away\n");
		printf("2. binary tree take away\n");
		printf("3. queue take away\n");
		printf("0. exit\n");
		printf("enter choice: ");

		if(scanf("%hhd", &module) != 1){
			while(getchar() != '\n');
			printf("Invalid input\n");
			continue;
		}
		switch(module){
			case 1: ex1(); break;
			case 2: ex2(); break;
			case 3: ex3(); break;
			case 0: return 0;
			default: printf("Invalid choice\n");
		}
	}
}
