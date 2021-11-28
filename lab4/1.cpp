#include <iostream>
#include <time.h>
using namespace std;

int binarySearch(int a[], int l, int r, int x)
{
  int mid;
  if (r >= l)
  {
    mid = (l + r) / 2;
    if (a[mid] == x) //Checking if elemnet is present at mid.
    {
      return mid + 1;
    }
    else if (a[mid] < x) //Checking if elemnet is present in greater half.
    {
      return binarySearch(a, mid + 1, r, x);
    }
    else //Checking if elemnet is present in samller half.
    {
      return binarySearch(a, l, mid - 1, x);
    }
  }
  return -1;
}
void display(int array[], int n)
{
  for (int i = 0; i < n; i++)
    cout << array[i] << "\t";
  cout << "\n";
}
int main()
{
  {
    clock_t start, end;
    double timeTaken;
    int array[50000], size, ch;
    int sz;

    cout << "Enter the case for testing (1: best, 2: avg, 3 worst):\n";
    cin >> ch;
    cout << "enter the number of array elements\n";
    cin >> size;
    start = clock();
    if (ch == 1)
    {
      for (int i = 0; i < size; i++)
      {
        array[i] = i + 1;
      }
    }
    else if (ch == 2)
    {
      for (int i = 0; i < size; i++)
      {
        array[i] = 1 + rand() % size;
      }
    }
    else
    {
      int k = 0;
      if (size % 2 == 0)
      {
        for (int i = 0; i < size / 2; i++)
        {
          array[i] = k++;
          array[size / 2 + i] = k++;
        }
      }
      else
      {
        for (int i = 0; i < size / 2 + 1; i++)
        {
          array[i] = k++;
          array[size / 2 + 1 + i] = k++;
        }
      }
    }

    cout << "original array\n";
    display(array, size);
    int number;
    cout << "enter the number to Searchrch\n";
    cin >> number;

    int location = binarySearch(array, 0, size, number);
    if (location != -1)
    {
      cout << "Search element found at" << location << " location"; //Printing the result.
    }
    else
    {
      cout << "Search element not present";
    }
    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "\nThe time taken for this case is\t" << timeTaken;
    cout << endl;
    return 0;
  }
}