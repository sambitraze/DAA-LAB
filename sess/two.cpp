#include <bits/stdc++.h>
using namespace std;

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size)
{
    cout << endl;
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

static int counter = 0;

void fifth_pass_qsort(int arr[], int low, int high)
{
    counter++;
    if (low < high)
    {
        int pi = partition(arr, low, high);
        if (counter < 5)
        {
            fifth_pass_qsort(arr, low, pi - 1);
        }
        else
        {
            cout << "\n5th pass occured";
            return;
        }
        if (counter < 5)
        {
            fifth_pass_qsort(arr, pi + 1, high);
        }
        else
        {
            cout << "\n5th pass occured";
            return;
        }
    }
}

int main()
{
    int n;
    cout<< "Enter the number of elements: ";
    cin>>n;
    int arr[n];
    bool close = false;
    int choice, random;

    cout<<"\n 0. quit";
    cout<<"\n 1. Random array generate";
    cout<<"\n 2. Print Array";
    cout<<"\n 3. Quick Sort";
    cout<<"\n 4. Fifth pass";

    do {
        cout<<"\n Enter your choice: ";
        cin>>choice;
        switch(choice) {
            case 0:
                close = true;
                cout<<"\n Program closed"<<endl;
                break;
            case 1:
                for(int i=0; i<n; i++) {
                    random = rand() % 100;
                    arr[i] = random;
                }
                printArray(arr, n);
                break;
            case 2:
                printArray(arr, n);
                break;
            case 3:
                quickSort(arr, 0, n-1);
                printArray(arr, n);
                break;
            case 4:
                fifth_pass_qsort(arr, 0, n-1);
                printArray(arr, n);
                break;
            default:
                cout<<"\n Wrong choice";
        }
    } while(!close);

    return 0;
}