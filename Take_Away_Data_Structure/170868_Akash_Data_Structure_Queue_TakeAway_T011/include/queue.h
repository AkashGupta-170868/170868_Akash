#ifndef HEADER_H
#define HEADER_H

#include <stdint.h>
#include <stdbool.h>

struct pnode
{
    char name[50];
    int32_t priority;
    struct pnode* next;
};

struct queue
{
    struct pnode* front;
};

struct pnode* createpnode(char* name, int32_t priority);
struct queue* createqueue(void);

void insertnode(struct queue* queue,
                char* name,
                int32_t priority);

void upgradePT(struct queue* queue,
               char* name,
               int32_t newPriority);

char* processqueue(struct queue* queue);

char* frontname(struct queue* queue);

int32_t frontpriority(struct queue* queue);

bool is_empty(struct queue* queue);

void clearnode(struct queue* queue);
void clearqueue(struct queue* queue);
void bulk(struct queue* queue);

#endif
