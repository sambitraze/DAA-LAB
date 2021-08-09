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

int main()
{
    int i, n;
    cout << "\nEnter the number of elements : ";
    cin >> n;
    int a[n], b[n];
    cout << "\nInput the array elements : ";
    for (i = 0; i < n; i++)
    {
        a[i] = getRandom();
        cout << a[i] << " ";
    }
    int a1, a2;
    a1 = a2 = a[0];
     for (i = 0; i < n; i++)
    {
       if(a[i] < a1){
           a2 = a1;
           a1 = a[i];
       }else if(a[i] < a2 && a[i] != a1 ){
           a2 = a[i];
       }
    }
    cout<<endl<<"Second largest : "<<a2<<endl;

    return 0;
}
