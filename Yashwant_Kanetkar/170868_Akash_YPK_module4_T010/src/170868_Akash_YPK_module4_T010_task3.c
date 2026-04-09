/* Write a program to list current directory alphabetically using LinkedList
 * Author: Akash Gupta
 * Created: 25 March,2026
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

struct Node {
    char name[256];
    struct Node *next;
};
/* Function name: insertSorted(struct **, const char)                                                                               
 * Function Description: This function is used to insert sorted name from file name of directory.
  * Author: Akash Gupta
  * Created: 25 March, 2026
  */
void insertSorted(struct Node **head, const char *fname) {
    struct Node *newNode = malloc(sizeof(struct Node));
    strcpy(newNode->name, fname);
    newNode->next = NULL;

    if (*head == NULL || strcmp(fname, (*head)->name) < 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node *current = *head;
    while (current->next != NULL &&
           strcmp(fname, current->next->name) > 0) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}
/* Function name: listDirectory()                                                                                                  
 * Function Description: This function is used to list the directory of user's choice.
  * Author: Akash Gupta
  * Created: 25 March, 2026
  */
void listDirectory() {
    char dirPath[1024];
    DIR *dir;
    struct dirent *entry;
    struct Node *head = NULL;

    printf("Enter directory path: ");
    if (scanf("%1023s", dirPath) != 1) {
        fprintf(stderr, "Invalid input.\n");
        return;
    }

    dir = opendir(dirPath);
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        insertSorted(&head, entry->d_name);
    }

    closedir(dir);

    printf("\nDirectory listing for: %s\n", dirPath);
    printf("----------------------------------\n");

    struct Node *temp = head;
    while (temp != NULL) {
        printf("%s\n", temp->name);
        temp = temp->next;
    }

    while (head != NULL) {
        struct Node *tmp = head;
        head = head->next;
        free(tmp);
    }
}

