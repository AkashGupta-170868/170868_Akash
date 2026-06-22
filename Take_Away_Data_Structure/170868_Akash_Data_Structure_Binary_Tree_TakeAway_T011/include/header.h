#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>

struct questionNode{
        char data[256];
        struct questionNode* yes;
        struct questionNode* no;
};

struct questionNode* createNode(char* data);
struct questionNode* buildtree(FILE* fp);
void writetree(FILE* fp, struct questionNode* root);
void playGame(struct questionNode* root);

#endif
