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

int main()
{
    int i, j, n, count = 0;
    cout<<"Enter size of the array : ";
    cin>>n;
    int arr[n];

    cout<<"Elements in array : ";
    for (i = 0; i < n; ++i)
    {
        arr[i] = getRandom();
        cout << arr[i]<< " ";
    } 

    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
        if(arr[i] == arr[j])
            {
                count++;
                break;
            }
        }
    }

    cout<< "\nNo of duplicates: " <<count;
}