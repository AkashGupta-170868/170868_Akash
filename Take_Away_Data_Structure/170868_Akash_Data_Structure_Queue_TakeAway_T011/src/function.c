#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include "queue.h"

/*
 * Function Name : createpnode
 * Description   : Creates a new patient node and initializes
 *                 the patient's name, priority and next pointer.
 * Author        : Akash Gupta
 * Created At    : 04 June 2026
 */
struct pnode* createpnode(char* name, int32_t priority)
{
        struct pnode* newnode = (struct pnode*)malloc(sizeof(struct pnode));

        if (newnode == NULL) {
                printf("Memory allocation failed\n");
                return NULL;
        }

        strcpy(newnode->name, name);
        newnode->priority = priority;
        newnode->next = NULL;

        return newnode;
}

/*
 * Function Name : createqueue
 * Description   : Creates and initializes an empty
 *                 priority queue.
 * Author        : Akash Gupta
 * Created At    : 04 June 2026
 */
struct queue* createqueue()
{
        struct queue* newqueue = (struct queue*)malloc(sizeof(struct queue));

        if (newqueue == NULL) {
                printf("Memory allocation failed\n");
                return NULL;
        }

        newqueue->front = NULL;

        return newqueue;
}

/*
 * Function Name : insertnode
 * Description   : Inserts a patient into the queue
 *                 according to priority order.
 * Author        : Akash Gupta
 * Created At    : 04 June 2026
 */
void insertnode(struct queue* queue,char* name,int32_t priority)
{
        if (queue == NULL)
                return;

        struct pnode* newnode =
                createpnode(name, priority);

        if (newnode == NULL)
                return;

        if (queue->front == NULL) {
                queue->front = newnode;
                return;
        }

        if (priority < queue->front->priority) {
                newnode->next = queue->front;
                queue->front = newnode;
                return;
        }

        struct pnode* temp = queue->front;

        while (temp->next != NULL &&
                        temp->next->priority <= priority) {
                temp = temp->next;
        }

        newnode->next = temp->next;
        temp->next = newnode;
}

/*
 * Function Name : clearnode
 * Description   : Frees all patient nodes present
 *                 in the queue.
 * Author        : Akash Gupta
 * Created At    : 04 June 2026
 */
void clearnode(struct queue* queue)
{
        if (queue == NULL)
                return;

        struct pnode* temp = queue->front;
        struct pnode* curr;

        while (temp != NULL) {
                curr = temp;
                temp = temp->next;
                free(curr);
        }

        queue->front = NULL;
}

/*
 * Function Name : clearqueue
 * Description   : Clears the queue and releases all
 *                 dynamically allocated memory.
 * Author        : Akash Gupta
 * Created At    : 04 June 2026
 */
void clearqueue(struct queue* queue)
{
        if (queue == NULL)
                return;

        clearnode(queue);
        free(queue);
}

/*
 * Function Name : is_empty
 * Description   : Checks whether the queue contains
 *                 any patient nodes.
 * Author        : Akash Gupta
 * Created At    : 04 June 2026
 */
bool is_empty(struct queue* queue)
{
        return (queue == NULL || queue->front == NULL);
}

/*
 * Function Name : processqueue
 * Description   : Removes and returns the highest
 *                 priority patient from the queue.
 * Author        : Akash Gupta
 * Created At    : 04 June 2026
 */
char* processqueue(struct queue* queue)
{
        if (queue == NULL ||
                        queue->front == NULL)
                return NULL;

        struct pnode* temp = queue->front;

        char* result = (char*)malloc(strlen(temp->name) + 1);

        if (result == NULL){
                return NULL;
        }

        strcpy(result, temp->name);

        queue->front = temp->next;

        free(temp);

        return result;
}

/*
 * Function Name : frontname
 * Description   : Returns the name of the patient
 *                 present at the front of the queue.
 * Author        : Akash Gupta
 * Created At    : 04 June 2026
 */
char* frontname(struct queue* queue)
{
        if (queue == NULL || queue->front == NULL){
                return NULL;
        }

        struct pnode* temp = queue->front;

        char* name = (char*)malloc(strlen(temp->name) + 1);

        if (name == NULL)
                return NULL;

        strcpy(name, temp->name);

        return name;
}

/*
 * Function Name : frontpriority
 * Description   : Returns the priority value of the
 *                 patient at the front of the queue.
 * Author        : Akash Gupta
 * Created At    : 04 June 2026
 */
int32_t frontpriority(struct queue* queue)
{
        if (queue == NULL ||
                        queue->front == NULL)
                return -1;

        return queue->front->priority;
}

/*
 * Function Name : tostring
 * Description   : Displays all patients stored in
 *                 the priority queue.
 * Author        : Akash Gupta
 * Created At    : 04 June 2026
 */
void tostring(struct queue* queue)
{
        if (queue == NULL) {
                printf("Queue is NULL\n");
                return;
        }

        if (queue->front == NULL) {
                printf("Queue is empty\n");
                return;
        }

        struct pnode* temp = queue->front;

        printf("\nPriority Queue:\n");

        while (temp != NULL) {
                printf("Name : %-20s Priority : %d\n",
                                temp->name,
                                temp->priority);

                temp = temp->next;
        }
}

/*
 * Function Name : bulk
 * Description   : Accepts multiple patient records
 *                 from the user and inserts them into
 *                 the queue.
 * Author        : Akash Gupta
 * Created At    : 04 June 2026
 */
void bulk(struct queue* queue)
{
        if (queue == NULL)
                return;

        int num;
        char name[50];
        int priority;

        printf("Enter number of patients: ");
        scanf("%d", &num);

        getchar();

        for (int i = 0; i < num; i++) {

                printf("\nPatient %d\n", i + 1);

                printf("Enter name: ");
                fgets(name, sizeof(name), stdin);

                name[strcspn(name, "\n")] = '\0';

                printf("Enter priority: ");
                scanf("%d", &priority);

                getchar();

                insertnode(queue, name, priority);
        }
}

/*
 * Function Name : printQueue
 * Description   : Prints the current contents of the
 *                 queue in {priority:name} format.
 * Author        : Akash Gupta
 * Created At    : 04 June 2026
 */
void printQueue(struct queue* queue)
{
    printf("\nCurrent patient queue:\n");

    if (is_empty(queue))
    {
        printf("{} (empty)\n");
        return;
    }

    printf("{");

    struct pnode* temp = queue->front;

    while (temp != NULL)
    {
        printf("%d:%s",
               temp->priority,
               temp->name);

        if (temp->next != NULL)
            printf(", ");

        temp = temp->next;
    }

    printf("} (not empty)\n");
}

/*
 * Function Name : upgradequeue
 * Description   : Updates the priority of an existing
 *                 patient and repositions the patient
 *                 according to the new priority.
 * Author        : Akash Gupta
 * Created At    : 04 June 2026
 */
void upgradequeue(struct queue* queue,
                  char* name,
                  int32_t newPriority)
{
    if (queue == NULL || queue->front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct pnode* current = queue->front;
    struct pnode* prev = NULL;

    struct pnode* target = NULL;
    struct pnode* targetPrev = NULL;

    while (current != NULL) {

        if (strcmp(current->name, name) == 0) {

            if (target == NULL ||
                current->priority < target->priority) {

                target = current;
                targetPrev = prev;
            }
        }

        prev = current;
        current = current->next;
    }

    if (target == NULL) {
        printf("Patient not found\n");
        return;
    }

    if (newPriority >= target->priority) {
        printf("New priority must be more urgent\n");
        return;
    }

    if (targetPrev == NULL) {
        queue->front = target->next;
    }
    else {
        targetPrev->next = target->next;
    }

    target->priority = newPriority;

    if (queue->front == NULL ||
        newPriority < queue->front->priority) {

        target->next = queue->front;
        queue->front = target;
        return;
    }

    current = queue->front;

    while (current->next != NULL &&
           current->next->priority <= newPriority) {

        current = current->next;
    }

    target->next = current->next;
    current->next = target;
}
