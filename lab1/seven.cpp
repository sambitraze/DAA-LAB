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

int main()
{
    int i, n, large, small;
    cout << "\nEnter the number of elements : ";
    cin >> n;
    int a[n];
    cout << "\nInput the array elements : ";
    for (i = 0; i < n; ++i)
    {
        a[i] = getRandom();
        cout << a[i] << " ";
    }

    for(i=0;i < n;i+=2)
    {
        if((i+1==n) && (n%2 != 0))
            continue;
        else
            swap(&a[i], &a[i+1]);
    }

    cout << "\nArray elements after swap: ";
    for (i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
    cout<<endl;
}