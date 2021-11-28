#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void findMinAndMax(int arr[], int low, int high, int *min, int *max)
{
    if (low == high)
    {
        if (*max < arr[low])
        {
            *max = arr[low];
        }

        if (*min > arr[high])
        {
            *min = arr[high];
        }
        return;
    }

    if (high - low == 1)
    {
        if (arr[low] < arr[high])
        {
            if (*min > arr[low])
            {
                *min = arr[low];
            }

            if (*max < arr[high])
            {
                *max = arr[high];
            }
        }
        else
        {
            if (*min > arr[high])
            {
                *min = arr[high];
            }

            if (*max < arr[low])
            {
                *max = arr[low];
            }
            return;
        }
    }

    int mid = (low + high) / 2;
    findMinAndMax(arr, low, mid, min, max);
    findMinAndMax(arr, mid + 1, high,min, max);
}

int main()
{
    int n;
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = 1 + rand() % n;
        printf("%d ", arr[i]);
    }
    int max, min;
    clock_t start,end;
        start=clock();
    findMinAndMax(arr, 0, n - 1,&min, &max);
        end=clock();
    printf("\nMax:%d", max);
    printf("\nMin:%d", min);
    printf("\nTime Taken:%lf\n", (end-start)/(double)CLOCKS_PER_SEC);

    return 0;
}