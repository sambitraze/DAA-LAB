#include <iostream>
using namespace std;

int getRandom()
{
    int lower = 0, upper = 10;
    int num = (rand() %
               (upper - lower + 1)) +
              lower;
    return num;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void arrange(int arr[], int size)
{
    int left = 0, right = size - 1;
    while (left < right)
    {
        while (arr[left] % 2 == 0 && left < right)
            left++;

        while (arr[right] % 2 == 1 && left < right)
            right--;

        if (left < right)
        {
            swap(&arr[left], &arr[right]);
            left++;
            right--;
        }
    }
}

int main()
{
    int n, i, j, temp;
    cout << "\nenter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "\nArray is: ";

    for (i = 0; i < n; ++i)
    {
        arr[i] = getRandom();
        cout << arr[i] << " ";
    }

    arrange(arr, n);

    cout << "\nArray after arrangement: ";
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}