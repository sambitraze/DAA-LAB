#include <iostream>
using namespace std;
void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int x, y, z;

    cout << "Enter three integers\n";
    cin >> x >> y >> z;

    cout << "Before Swapping\n";
    cout << "X = "<<x<<", Y = "<<y<<", Z = "<<z << endl;

    swap(&x, &y);
    swap(&x, &z);

    cout << "After Swapping\n";
    cout << "X = "<<x<<", Y = "<<y<<", Z = "<<z;

    return 0;
}