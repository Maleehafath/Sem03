#include <iostream>
using namespace std;

int main()
{
    int a[100], n, x;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter element to insert: ";
    cin >> x;

    for (int i = n; i > 0; i--)
        a[i] = a[i - 1];

    a[0] = x;
    n++;

    cout << "Array after insertion: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}