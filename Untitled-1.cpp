/*
3.  WAP in C to store 1 million integers in an array. To search 
an element in that array and find out its time complexity (best, 
worst, and average). 
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void searchElement(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            printf("\nFound at index: %d\n", i);
            break;
        }
    }
}

void printArray(int arr[], int size)
{
    printf("\nThe Array:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    clock_t start, mid, end;

    int arr[1000000], size, key, temp, choice;
    start = clock();

    printf("\nEnter the number of elements: ");
    scanf("%d", &size);
    printf("%d\n", size);

    printf("\nEnter the key to search: ");
    scanf("%d", &key);

    printf("\nChoice 1: Best Case");
    printf("\nChoice 2: Average Case");
    printf("\nChoice 3: Worst Case");
    printf("\nEnter choice: ");
    scanf("%d", &choice);

    // printf("\n");
    for (int i = 0; i < size; i++)
    {
        temp = rand() % size;
        if (temp == key)
        {
            temp++;
        }
        arr[i] = temp;
        // printf("%d ", arr[i]);
    }
    // printf("\n");

    mid = clock();

    if (choice == 1)
    {
        printf("\nFor best case:\n");
        arr[0] = key;
    }
    else if (choice == 2)
    {
        printf("\nFor avg case:\n");
        arr[size / 2] = key;
    }
    else if (choice == 3)
    {
        printf("\nFor worst case:\n");
        arr[size - 1] = key;
    }
    else
    {
        printf("\nWRONG CHOICE\n");
    }

    // printArray(arr, size);

    searchElement(arr, size, key);

    end = clock();

    printf("\nClock Start: %ld", start);
    printf("\nClock Mid: %ld", mid);
    printf("\nClock End: %ld\n", end);
    printf("\nStart-Mid Time: %fsec", ((double)(mid - start)) / CLOCKS_PER_SEC);
    printf("\nMid-End Time: %fsec", ((double)(end - mid)) / CLOCKS_PER_SEC);
    printf("\nStart-End Time: %fsec\n", ((double)(end - start)) / CLOCKS_PER_SEC);
}