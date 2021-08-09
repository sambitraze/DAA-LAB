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
        cout << a[i]<< " ";
    }

    large = small = a[0];

    for (i = 1; i < n; ++i)
    {
        if (a[i] > large)
            large = a[i];

        if (a[i] < small)
            small = a[i];
    }

    cout << "\nThe smallest element is " << small << endl;
    cout << "\nThe largest element is " << large << endl;

    return 0;
}