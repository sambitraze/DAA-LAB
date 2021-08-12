#include <iostream>
using namespace std;
void findElement(int arr[], int n)
{
    cout << "UDF for finding the elements by O(n^2) time complexity\n";
    int max_element = 0, i, j;
    int index = -1;
    for (i = 0; i < n; i++)
    {
        int count = 0;
        for (j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
                count++;
        }
        if (count > max_element)
        {
            max_element = count;
            index = i;
        }
    }
    if (max_element > n / 2)
        cout << "element with n/2 occurance are present\t" << endl;
    else
        cout << "No element present which is equal to n/2" << endl;
}
int main()
{
    int n;

    cout << "Enter the size of the array\n";
    cin >> n;
    int arr[n];
    cout << "enter the array elements\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    findElement(arr, n);
    return 0;
}