#include <iostream>
using namespace std;

double isqrt(int num)
{
    double root = 1;
    int i = 0;

    while (1)
    {
        i = i + 1;
        root = (num / root + root) / 2;
        if (i == num + 1)
        {
            break;
        }
    }
    return root;
}
int main()
{
    int n;
    double ans;
    cout << "\nEnter the a number : ";
    cin >> n;
    ans = isqrt(n);
    cout << "\nSquare root of " << n << " is = " << int (ans) << endl;
}