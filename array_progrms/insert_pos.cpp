#include <iostream>
using namespace std;

int main()
{
    int a[100], n, x, pos;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter element to insert: ";
    cin >> x;

    cout << "Enter position: ";
    cin >> pos;

    for (int i = n; i >= pos; i--)
        a[i] = a[i - 1];

    a[pos - 1] = x;
    n++;

    cout << "Array after insertion: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}