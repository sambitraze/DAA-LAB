#include <iostream>
using namespace std;

int getRandom()
{
    int lower = 1, upper = 5;
    int num = (rand() %
               (upper - lower + 1)) +
              lower;
    return num;
}

int getProductArray(int *a, int n, int index)
{
    int prod = 1;
    for (int i = 0; i < n; i++)
    {
        if (i == index)
            continue;
        else
        {
            prod = prod * (*(a + i));
        }
    }
    return prod;
}

int main()
{
    int i, n;
    cout << "\nEnter the number of elements : ";
    cin >> n;
    int a[n], b[n];
    cout << "\nInput the array elements : ";
    for (i = 0; i < n; ++i)
    {
        a[i] = getRandom();
        cout << a[i] << " ";
    }
    cout << "\nProduct array elements : ";
    for (i = 0; i < n; ++i)
    {
        b[i] = getProductArray(a, n, i);
        cout << b[i] << " ";
    }
    cout << endl;
}
