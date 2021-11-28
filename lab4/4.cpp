#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;
 int getRandom(int upper)
{
    int lower = 1;
    int num = (rand() %
                         (upper - lower + 1)) +
                        lower;
    return num;
}
int power_BF(int a, int n)
{
    long prod = 1, i = 0;
    for (; i < n; i++)
        prod = prod * a;
    return prod;
}
int power_DAC(int a, int n)
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
    int result;
    for (int i = 0; i < 5; i++)
    {
        int a = getRandom(i * 10), n = getRandom(i * 10);
        clock_t start, end;
        long timeTaken;

        start = clock();
        result = power_BF(a, n);
        end = clock();
        timeTaken = (end - start) /(double)CLOCKS_PER_SEC;
        cout << "\nThe time taken for this case is\n"
             << timeTaken;
        cout << "\n";

        start = clock();
        result = power_DAC(a, n);
        end = clock();
        timeTaken = (end - start) /(double)CLOCKS_PER_SEC;

        cout << "\nThe time taken for this case is\n"
             << timeTaken;
        cout << "\n";
    }

    return 0;
}