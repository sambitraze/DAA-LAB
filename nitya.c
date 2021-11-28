#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swapNumbers(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
int partition(int arr[], int start, int end)
{
    int pivot = arr[end];
    int i = (start - 1);

    for (int j = start; j <= end - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swapNumbers(&arr[i], &arr[j]);
        }
    }
    swapNumbers(&arr[i + 1], &arr[end]);
    return (i + 1);
}

void quickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int pi = partition(arr, start, end);

        quickSort(arr, start, pi - 1);
        quickSort(arr, pi + 1, end);
    }
}

void printArray(int array[], int size)
{
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", array[i]);
    }
    printf("\n");
}

int main()
{
    clock_t start, end;
    double timeTaken;

    start = clock();

    int array[50000], size;

    printf("\nEnter the number of elements: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++)
    {
        array[i] = 1 + rand() % size;
    }

    printArray(array, size);
    quickSort(array, 0, size-1);
    printArray(array, size);

    // printf("\nEnter the elements:\n");
    // for (int i = 0; i < size; i++)
    // {
    //     printf("Element %d: ", i);
    //     scanf("%d", &array[i]);
    // }

    end = clock();

    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nTime Taken: %f\n\n", timeTaken);

    return 0;
}