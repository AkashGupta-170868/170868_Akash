/*Description : function about binary search which takes array and its length and which value to find .
 *Author : Akash Gupta
 *created at : 24-02-2026
 *modifid at : 25-02-2026
 */
/*#include <stdint.h>
#include <stdio.h>

int binarySearch(int arr[], int size, int target);

void binarySearchTest(void)
{
    int size;
    int target;
    int result;

    printf("Enter number of elements (max 100): ");
    scanf("%d", &size);
	int arr[size];

    if (size <= 0 || size > 100)
    {
        printf("Invalid array size!\n");
        return;
    }

    printf("Enter %d elements in sorted order:\n", size);

    for (int i = 0; i < size; i++)
    {
        printf("Element [%d]: ", i);
        scanf("%d", &arr[i]);
    }
	
    printf("Enter target value to search: ");
    scanf("%d", &target);

    result = binarySearch(arr, size, target);

    if (result != -1)
        printf("Target found at index: %d\n", result);
    else
        printf("Target not found in the array.\n");
}

int binarySearch(int arr[], int size, int target)
{
    int low = 0;
    int high = size - 1;
    int mid;

    while (low <= high)
    {
        mid = low + (high - low) / 2;   // safely calculating mid valur

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}*/
