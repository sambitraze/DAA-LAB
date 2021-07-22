#include <iostream>
using namespace std;

int getRandom()
{
    int lower = 0, upper = 5;
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

void bubbleSortArrayAsscending(int *arr, int n)
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            if (*(arr + i) < *(arr + j))
                swap(*(arr + i), *(arr + j));
        }
}

void bubbleSortArrayDescending(int *arr, int n)
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            if (*(arr + i) > *(arr + j))
                swap(*(arr + i), *(arr + j));
        }
}

int main()
{
    int i, n;
    cout << "\nEnter the number of elements : ";
    cin >> n;
    int a[n];
    cout << "\nInput the array elements : ";
    for (i = 0; i < n; ++i)
    {
        a[i] = getRandom();
        cout << a[i] << " ";
    }

    bubbleSortArrayAsscending(&a[0], n);
    cout << "\nThe numbers arranged in Asscending order are given below ";

    for (i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    
    cout << "The 2nd smallest number is  = " << a[1];

    
    bubbleSortArrayDescending(&a[0], n);
    cout << "\nThe numbers arranged in descending order are given below ";

    for (i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "The 2nd largest number is  = " << a[1];

    cout << endl;

    return 0;
}