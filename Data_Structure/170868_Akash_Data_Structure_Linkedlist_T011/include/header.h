#ifndef HEADER_H
#define HEADER_H

#include <stdint.h>

struct node
{
    int32_t data;
    struct node *next;
};

void count_main(void);
void getnth_main(void);
void DeleteListTest(void);

#endif
