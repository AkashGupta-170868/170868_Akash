#include <stdio.h>
#include <string.h>

int test_3()
{
    char *names[] = {
        "Santosh",
        "Amol",
        "Santosh Jain",
        "Kishore",
        "Rahul",
        "Amolkumar",
        "Hemant"
    };

    int n = 7;
    char *temp;

    // Bubble sort
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strcmp(names[j], names[j + 1]) > 0)
            {
                temp = names[j];
                names[j] = names[j + 1];
                names[j + 1] = temp;
            }
        }
    }

    // Print sorted names
    printf("Sorted Names:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", names[i]);
    }

    return 0;
}
