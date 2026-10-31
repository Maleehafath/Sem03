
#include <iostream>
using namespace std;

int main()
{
    int a[100], n, pos;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter position to delete: ";
    cin >> pos;

    for (int i = pos - 1; i < n - 1; i++)
        a[i] = a[i + 1];

    n--;

    cout << "Array after deletion: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
