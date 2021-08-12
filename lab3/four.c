#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int maxSubArray(int nums[9], int n)
{
    int l = n;
    int i = 0, s = 0, max = nums[0];
    int b[l];

    while (i != l)
    {
        b[i] = nums[i];
        i++;
    }
    for (int k = 0; k < l; ++k)
    {

        for (int j = i + 1; j < l; ++j)
        {

            if (nums[k] > nums[j])
            {

                int a = nums[i];
                nums[i] = nums[j];
                nums[j] = a;
            }
        }
    }
    if (b[l - 1] <= 0)
        return b[l - 1];

    i = 0;
    while (i != l)
    {
        s += nums[i];
        if (s < 0)
        {
            s = 0;
        }
        else if (s > max)
            max = s;
        i++;
    }
    return max;
}

int main()
{
    clock_t start, end;
    int n = 0;
    printf("Enter no of elements: ");
    scanf("%d", &n);
    int A[n];
    for (int k = 0; k < n; ++k)
    {
        printf("Enter element %d: ", k+1);
        scanf("%d", &A[k]);
    }
    start = clock();
    int res = maxSubArray(A, n);
    end = clock();
    printf("Largest subarray sum: %d", res);
    printf("Time: %fsec", (end-start)/(double)CLOCKS_PER_SEC);
    return 0;
}