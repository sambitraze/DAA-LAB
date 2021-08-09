#include <iostream>
#include <iomanip>
using namespace std;

int euclid_gcd(int x, int y)
{
    int count = 0;
    while (y > 0)
    {
        count++;
        int r = x % y;
        count++;
        x = y;
        count++;
        y = r;
        count++;
    }
    return count;
}
int consecutive_int_checking_gcd(int x, int y)
{
    int count = 0;
    int c;
    count++;
    c = x >= y ? y : x;
    count++;
    count++;
    for (int i = c; i >= 1; i--)
    {
        count++;
        if (x % i == 0 && y % i == 0)
        {
            count++;
            break;
        }
    }
    return count;
}
int middle_school_gcd(int x, int y)
{
    int count = 0;
    int c, ans = 1, m, n;
    count++;
    c = x >= y ? y : x;
    count++;
    count++;
    for (int i = 2; i < c; i++)
    {
        n = 0;
        count++;
        m = 0;
        count++;
        if (x % i == 0)
        {
            count++;
            n = 1;
            count++;
            x /= i;
            count++;
        }

        count++;
        if (y % i == 0)
        {

            count++;
            m = 1;

            count++;
            y /= i;

            count++;
        }
        if (n == 1 && m == 1)
        {
            count++;
            ans *= i;
            count++;
        }
        if (n == 1 || m == 1)
        {
            count++;
            i--;
            count++;
        }
    }
    return count;
}

string remarkGen(int n1,int n2,int n3)
{
    string ans = "EC";
    if (n1 <= n2 && n1 <= n3)
        ans = "EC";
    else if (n2 <= n1 && n2 <= n3)
        ans = "CCI";
    else if (n3 <= n1 && n3 <= n2)
        ans = "MSP";
    return ans;
}

int main()
{
    int input_List[6][2] = {{31415, 14142},
                                      {56, 32566},
                                      {34218, 56},
                                      {12, 15},
                                      {31415, 31415},
                                      {12, 12}};
    int EC[6];
    int CIC[6];
    int MSA[6];
    int remarks[6];
    cout << "\nSl No.\tGCD Input X\tGCD Input Y\tEC Algorithm\tCCI Algorithm\tMSP Algorithm\tRemarks\n";
    cout << "-----------------------------------------------------------------------------------------------\n";

    for (int i = 0; i < 6; i++)
    {
        int a = input_List[i][0];
        int b = input_List[i][1];
        EC[i] = euclid_gcd(a, b);
        CIC[i] = consecutive_int_checking_gcd(a, b);
        MSA[i] = middle_school_gcd(a, b);
        string ans = remarkGen(EC[i],CIC[i],MSA[i]);
        cout << setw(5) << i+1 << "\t" << setw(11) << a << "\t" << setw(11) << b <<  "\t" << setw(12) << EC[i] << "\t" << setw(13) << CIC[i] << "\t" << setw(12) << MSA[i] << "\t" << setw(7) << ans << "\t" << endl;
    }
    return 0;
}