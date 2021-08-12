#include <iostream>
using namespace std;
void findElement(int arr[], int n,int x)
{
    cout << "UDF for finding the elements by O(n) time complexity\n";
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
            count++;
    }
    if (count > n / 2)
        cout << "element with n/2 occurance are present\t" << endl;
    else
        cout << "No element present which is equal to n/2" << endl;
}
int main()
{
    int n,x;

    cout << "Enter the size of the array\n";
    cin >> n;
    int arr[n];
    cout << "enter the array elements\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    cout << "Enter the elemnt to find \n";
    cin >> n,x;

    findElement(arr, n,x);
    return 0;
}