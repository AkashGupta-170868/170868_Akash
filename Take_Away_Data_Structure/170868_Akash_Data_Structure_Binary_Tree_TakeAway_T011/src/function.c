#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "/home/akash/Take_Away_Data_Structure/170868_Akash_Data_Structure_Binary_Tree_TakeAway_T011/include/header.h"
/*
function name : createNode();\
description : creating node with default value;
author : akash gupta
created at : 02 june
*/
struct questionNode* createNode(char* data){
	struct questionNode* newNode = (struct questionNode*)malloc(sizeof(struct questionNode));
	if ( newNode == NULL){	
		return NULL;
	}
	strcpy(newNode->data, data);
	newNode->yes = NULL;
	newNode->no = NULL;

	return newNode;
}
/*
function name : buildtree();\
description : building  a tree from the question.txt and return root node.
author : akash gupta
created at : 02 june
*/
struct questionNode* buildtree(FILE* fp) {
	char line[100];
	if (!fgets(line,sizeof(line),fp))
		return NULL;
	line[strcspn(line,"\n")] = '\0';
	char* text = line+2;
	struct questionNode* root = createNode(text);
	if(line[0] == 'Q'){
		root->yes = buildtree(fp);
		root->no = buildtree(fp);
	}
	return root;
}		
/*
function name : writetree();\
description : if the root's leaf node would be null then writing answer in the file otherwise it is a question.
author : akash gupta
created at : 02 june
*/
void writetree(FILE* fp, struct questionNode* root){
	if ( root == NULL)
		return;

	if ( root->yes == NULL && root->no == NULL){
		fprintf(fp,"A:%s\n",root->data);
	}else {
		fprintf(fp,"Q:%s\n",root->data);
		writetree(fp,root->yes);
		writetree(fp,root->no);
	}
}
/*
function name : playGame();
description : ask from the user 
author : akash gupta
created at : 02 june
*/

void playGame(struct questionNode* root) {

	char ans[10];

	if (root == NULL)
		return;

	/* Answer Node */
	if (root->yes == NULL && root->no == NULL) {

		printf("Are you thinking of %s ? (y/n): ",root->data);
		scanf("%s", ans);
		getchar();

		if (ans[0] == 'y' || ans[0] == 'Y') {
			printf("Hey, I win!\n");
		}
		else {
			char object[100];
			char question[100];

			printf("I lost!\n");

			printf("What was your object? ");
			fgets(object, sizeof(object), stdin);
			object[strcspn(object, "\n")] = '\0';

			printf("Enter a question to distinguish %s from %s:\n",object,root->data);

			fgets(question, sizeof(question), stdin);
			question[strcspn(question, "\n")] = '\0';

			printf("For %s what is the answer? (y/n): ",object);

			scanf("%s", ans);
			getchar();

			struct questionNode* oldAnswer = createNode(root->data);

			struct questionNode* newAnswer = createNode(object);

			strcpy(root->data, question);

			if (ans[0] == 'y' || ans[0] == 'Y') {
				root->yes = newAnswer;
				root->no = oldAnswer;
			}else {
				root->yes = oldAnswer;
				root->no = newAnswer;
			}
		}

		return;
	}

	/* Question Node */

	printf("%s (y/n): ", root->data);

	scanf("%s", ans);
	getchar();

	if (ans[0] == 'y' || ans[0] == 'Y')
		playGame(root->yes);
	else
		playGame(root->no);
}
