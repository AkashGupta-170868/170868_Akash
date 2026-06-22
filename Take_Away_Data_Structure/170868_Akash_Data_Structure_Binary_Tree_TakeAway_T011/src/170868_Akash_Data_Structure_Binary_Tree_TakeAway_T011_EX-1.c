#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
/*
function name : game();\
description : calling the utility function to build a entire program using tree.
author : akash gupta
created at : 02 june
*/
int32_t game() {

	FILE* fp = fopen("/home/akash/Take_Away_Data_Structure/170868_Akash_Data_Structure_Binary_Tree_TakeAway_T011/question.txt", "r");

	if (fp == NULL) {
		printf("Unable to open question.txt\n");
		return 1;
	}

	struct questionNode* root = buildtree(fp);

	fclose(fp);

	printf("Think of an object.\n\n");

	playGame(root);

	fp = fopen("/home/akash/Take_Away_Data_Structure/170868_Akash_Data_Structure_Binary_Tree_TakeAway_T011/question.txt", "w");

	if (fp == NULL) {
		printf("Unable to write question.txt\n");
		return 1;
	}

	writetree(fp, root);

	fclose(fp);

	return 0;
}
