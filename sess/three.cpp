#include <iostream>
using namespace std;

bool isprime(int n)
{
    cout << "input(" << n << ")" << endl;
    int count = 0;
    for (int i = 2; i <= n; i++)
    {
        if (n % i == 0)
            count = 1;
        break;
    }
    if (count == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int n, num = 1;
    cout << "Enter a number\n";
    cin >> n;
    int c = 0;
    
    while (true)
    {
        if (isprime(num))
        {
            c++;
        }
        if (c == n)
        {
            cout << "The prime number is\t" << num;
            break;
        }
        num++;
    }
    return 0;
}