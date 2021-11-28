#include <iostream>
#include <time.h>
using namespace std;

long long int getRandom(long long int upper)
{
    long long int lower = 0;
    long long int num = (rand() %
                         (upper - lower + 1)) +
                        lower;
    return num;
}
void merge(int array[], int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
  
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
  
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
  
    auto indexOfSubArrayOne = 0,
        indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;
  
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}
  
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively
  
    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

void loop(int ch, int size)
{
    int array[100000];

    clock_t start, end;
    long timeTaken;
    start = clock();

    if (ch == 1)
    {
        for (long long int i = 0; i < size; i++)
        {
            array[i] = getRandom(size);
        }
    }
    else if (ch == 2)
    {
        for (long long int i = 0; i < size; i++)
        {
            array[i] = getRandom(size);
        }
    }
    else
    {
        long long int k = 0;
        if (size % 2 == 0)
        {
            for (long long int i = 0; i < size / 2; i++)
            {
                array[i] = k++;
                array[size / 2 + i] = k++;
            }
        }
        else
        {
            for (long long int i = 0; i < size / 2 + 1; i++)
            {
                array[i] = k++;
                array[size / 2 + 1 + i] = k++;
            }
        }
    }

    mergeSort(array, 0, size - 1);

    end = clock();

    timeTaken = (end - start) / (double)CLOCKS_PER_SEC;
    cout << "The time taken for this case is\n"
         << timeTaken;
    cout << "\n";
}

int main()
{
    for (int i = 0; i < 5; i++)
    {
        loop(1, 100 * 1);
        loop(2, 100 * 1);
        loop(3, 100 * 1);
    }
    return 0;
}