#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;
long power_BF(int a, int n)
{
    long prod = 1, i = 0;
    for (; i < n; i++)
        prod = prod * a;
    return prod;
}
long power_DAC(int a, int n)
{
    if (n == 0)
        return 0;
    // putting a check to avoid unnecessary recursive calls
    if (a == 0)
        return 0;
    if (n % 2 == 0) // b is even
        return power_DAC(a * a, n / 2);
    else
        return a * power_DAC(a * a, n / 2);
}
int main()
{
    long result;
    int ch;
    cout << "Enter choice to compute\n1, Brute Force\t2.Divide and conquer\n";
    cin >> ch;
    int a, n;
    cout << "Enter a number\n";
    cin >> a;
    cout << "Enter a power value\n";
    cin >> n;
    clock_t start, end;
    long timeTaken;

    switch (ch)
    {
    case 1:
        cout << "using simple algo\n";
        result = power_BF(a, n);
        cout << "the answer is \t" << result;
        break;
    case 2:
        cout << "using simple algo\n";
        result = power_DAC(a, n);
        cout << "the answer is \t" << result;
        break;
    default:
        cout << "no such case\n";
    }
    end = clock();

    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "\nThe time taken for this case is\n"
         << timeTaken;
    cout << "\n";
    return 0;
}