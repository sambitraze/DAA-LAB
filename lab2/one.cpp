#include <iostream>
#include <iomanip>
using namespace std;

int algo1(int n)
{
    int step = 0;
    bool count = 0;
    step++;
    for (int i = 2; i < n; i++)
    {
        step++;
        if (n % i == 0)
        {
            step++;
            count = 1;
            step++;
            break;
        }
    }
    return step;
}
int algo2(int n)
{

    int step = 0;
    bool count = 0;
    step++;
    step++;
    for (int i = 2; i <= n / 2; i++)
    {
        step++;
        if (n % i == 0)
        {
            step++;
            count = 1;
            step++;
            break;
        }
    }

    return step;
}
int algo3(int n)
{

    int step = 0;
    bool count = 0;
    step++;
    step++;
    for (int i = 2; i * i <= n; i++)
    {
        step++;
        if (n % i == 0)
        {
            step++;
            count = 1;
            step++;
            break;
        }
    }

    return step;
}
int getRandom()
{
    int lower = 100, upper = 1000;
    int num = (rand() %
               (upper - lower + 1)) +
              lower;
    return num;
}
string remarkGen(int n1,int n2,int n3)
{
    string ans = "ALGO1";
    if (n1 <= n2 && n1 <= n3)
        ans = "ALGO1";
    else if (n2 <= n1 && n2 <= n3)
        ans = "ALGO2";
    else if (n3 <= n1 && n3 <= n2)
        ans = "ALGO3";
    return ans;
}
int main()
{
    cout << "\nSl No.\tInput\tAlgorithm1\tAlgorithm2\tAlgorithm3\tRemarks\n";
    cout << "-----------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < 10; i++)
    {
        int input = getRandom();
        int ans1 = algo1(input);
        int ans2 = algo2(input);
        int ans3= algo3(input);        
        string ans = remarkGen(ans1,ans2,ans3);
        cout << setw(5) << i+1 << "\t" << setw(5) << input << "\t" << setw(10) << ans1 << "\t" << setw(10) << ans2 << "\t" << setw(10) << ans3 << "\t" << setw(7) << ans << endl;
    }

    return 0;
}