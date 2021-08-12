#include <iostream>
using namespace std;
int findRoot(int n)
{
    if (n < 0)
    {
        return -1;
    }
    else if (n == 0)
    {
        return 0;
    }
    int st = 0, en = n;
    while (st <= en)
    {
        int mid = (st + en) / 2;
        if (mid * mid == n)
        {
            return mid;
        }
        else if (mid * mid < n)
        {
            st = mid + 1;
        }
        else
        {
            en = mid - 1;
        }
    }
    return en;
}

int main()
{
    int n;
    cout << "Enter the number:";
    cin >> n;
    int result = findRoot(n);
    if (result != -1)
    {
        cout << "Sqaure Root=" << result;
    }
    else
    {
        cout << "Invalid Input\n";
    }
    return 0;
}