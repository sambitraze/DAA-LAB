#include <iostream>
using namespace std;

void nonZeroCheck(int *arr, int n)
{
    int count = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (*((arr + i * n) + j) == 0)
                count++;

    cout << "No of non zero: " << count << endl;
}

void sumAboveLeading(int *arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (j > i)
                sum += *((arr + i * n) + j);

    cout << "Sum above leading Diagonal: " << sum;
}

void printBelowMinor(int *arr, int n)
{
    cout << "\nElements below minor diagonal: ";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (j < i)
                cout << *((arr + i * n) + j) << " ";
}

void productDiagonal(int *arr, int n)
{
    int productLeading = 1;
    int productMinor = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {   
            if (i == j)
                productLeading = productLeading * *((arr + i * n) + j);
            else if (i + j == n - 1)
                productMinor = productMinor * *((arr + i * n) + j);
        }
    }

    cout << "\nProduct leading Diagonal: " << productLeading << endl;
    cout << "Product Minor Diagonal: " << productMinor << endl;
}

int main()
{
    int n;
    cout << "\nenter number of elements: ";
    cin >> n;
    int arr[n][n];

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << "Enter element A" << i + 1 << j + 1 << " : ";
            cin >> arr[i][j];
        }
    }
    cout << "\nArray Elements:\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    nonZeroCheck(*arr, n);
    sumAboveLeading(*arr, n);
    printBelowMinor(*arr, n);
    productDiagonal(*arr, n);
}