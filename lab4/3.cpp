#include <iostream>
#include <climits>
using namespace std;

long long int getRandom(long long int upper)
{
    long long int lower = 0;
    long long int num = (rand() %
                         (upper - lower + 1)) +
                        lower;
    return num;
}

// Divide and conquer solution to find the minimum and maximum number in an array
void findMinAndMax(long long int arr[], long long int low, long long int high, long long int &min, long long int &max)
{
    if (low == high) // common comparison
    {
        if (max < arr[low])
        { // comparison 1
            max = arr[low];
        }

        if (min > arr[high])
        { // comparison 2
            min = arr[high];
        }
        return;
    }
    if (high - low == 1) // common comparison
    {
        if (arr[low] < arr[high]) // comparison 1
        {
            if (min > arr[low])
            { // comparison 2
                min = arr[low];
            }

            if (max < arr[high])
            { // comparison 3
                max = arr[high];
            }
        }
        else
        {
            if (min > arr[high])
            { // comparison 2
                min = arr[high];
            }

            if (max < arr[low])
            { // comparison 3
                max = arr[low];
            }
        }
        return;
    }
    int mid = (low + high) / 2;
    findMinAndMax(arr, low, mid, min, max);
    findMinAndMax(arr, mid + 1, high, min, max);
}

void find(long long int a[], long long int n, long long int &small, long long int &large)
{
    large = small = a[0];

    for (int i = 1; i < n; ++i)
    {
        if (a[i] > large)
            large = a[i];

        if (a[i] < small)
            small = a[i];
    }
}

int main()
{

    clock_t start, end;
    long long int nos[] = {1, 10, 100, 1000, 10000, 100000, 1000000};
    double a;

    for (int i = 0; i < 7; i++)
    {
        long long int arr[nos[i]];
        long long int n = nos[i];
        for (long long int j = 0; j < nos[i]; j++)
        {
            arr[j] = getRandom(n);
        }

        long long int max = LONG_LONG_MIN, min = LONG_LONG_MAX;

        start = clock();
        findMinAndMax(arr, 0, n - 1, min, max);
        end = clock();
        a = (end - start) / (double)CLOCKS_PER_SEC;
        cout << "\nLoop " << i+1 <<" Time using DNC = " << a << endl;

        long long int max1 = LONG_LONG_MIN, min1 = LONG_LONG_MAX;

        start = clock();
        find(arr, n, min1, max1);
        end = clock();
        a = (end - start) / (double)CLOCKS_PER_SEC;
        cout << "\nLoop " << i+1 <<" Time using Normal = " << a << endl;
    }

    return 0;
}