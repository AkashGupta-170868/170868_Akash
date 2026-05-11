#include <stdio.h>

void print_hello();
void print_bye();

int main() {
    int choice;
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            print_hello() ;
            break;
        case 2:
            print_bye() ;
            break;
        default:
            printf("Invalid choice\n");
    }
    return 0;
}

