#include "array1.h"
 
template <class T>
void array1<T>::setLB(int x)
{
    lb = x;
}
 
template <class T>
void array1<T>::setUB(int x)
{
    ub = x;
}
 
template <class T>
int array1<T>::getLB()
{
    return lb;
}
 
template <class T>
int array1<T>::getUB()
{
    return ub;
}
 
// ---- Constructor ----
// Starts the array "empty" using the convention lb=1, ub=0
// (i.e. ub < lb means there are zero elements: size = ub-lb+1 = 0).
// The for-loop below never actually runs in that state (1 <= 0 is
// false), so it's a harmless no-op safety net.
template <class T>
array1<T>::array1()
{
    lb = 1;
    ub = 0;
    for (int i = lb; i <= ub; i++)
        a[i] = 0;
}
 
// ---- Fill the array from user input ----
// Reads one value for every index from lb to ub.
// setLB()/setUB() must be called first so the loop knows the range.
template <class T>
void array1<T>::create()
{
    int i;
    cout << "enter the elements";
    for (i = lb; i <= ub; i++)
        cin >> a[i];
}
 
// ---- Insert at the beginning ----
// Shifts every existing element one slot to the right (starting
// from the end, so nothing gets overwritten), then places the new
// value at index lb.
template <class T>
void array1<T>::insert_at_beginning(T key)
{
    for (int i = ub; i >= lb; i--)
    {
        a[i + 1] = a[i];
    }
    a[lb] = key;
    ub = ub + 1;
}
 
// ---- Insert at the end ----
// No shifting needed -- just drop the new value one slot past ub.
template <class T>
void array1<T>::insert_at_end(T key)
{
    int pos = ub + 1;
    a[pos] = key;
    ub = ub + 1;
}
// ---- Insert at a specific position ----
// Valid positions are lb..ub (inserting exactly at ub+1 is handled
// by insert_at_end instead). Elements from ub down to p are shifted
// one slot right to make room, then key is placed at index p.
template <class T>
void array1<T>::insert_at_position(int p, T key)
{
    if (p > ub || p < lb)
    {
        cout << "invalid position" << endl;
        return;
    }
 
compilation terminated.
    for (int i = ub; i >= p; i--)
    {
        a[i + 1] = a[i];
    }
    a[p] = key;
    ub = ub + 1;
}
 
// ---- Delete from the end ----
// Simply shrinks the range by moving ub back one slot; the old
// value is left in the backing array but is now outside [lb, ub]
// so it's logically "gone".
template <class T>
void array1<T>::delete_at_end()
{
    ub = ub - 1;
}
 
// ---- Delete from the beginning ----
// Shifts every element one slot to the left, overwriting a[lb],
// then shrinks the range by decrementing ub.
template <class T>
void array1<T>::delete_at_beginning()
{
    for (int i = lb; i <= ub - 1; i++)
    {
        a[i] = a[i + 1];
    }
    ub = ub - 1;
}
 
// ---- Delete at a specific position ----
// Shifts everything after position p one slot to the left,
// closing the gap, then shrinks the range.
template <class T>
void array1<T>::delete_at_position(int p)
{
    if (p > ub || p < lb)
    {
        cout << "invalid position" << endl;
               return;
    }
    for (int i = p; i <= ub - 1; i++)
    {
        a[i] = a[i + 1];
    }
    ub = ub - 1;
}
 
// ---- Stream insertion operator (operator<<) ----
// Lets you write "cout << arr" instead of manually looping over
// arr's elements. Defined as a free (non-member) function -- see
// the write-up for why. Declared "friend" inside the class so it
// can reach m.lb, m.ub, and m.a directly even though they're private.
template <class U>
ostream& operator<<(ostream& os, const array1<U>& m)
{
    int i;
    os << endl;
    for (i = m.lb; i <= m.ub; i++)
        os << m.a[i] << " ";
    os << endl;
    return os;   // returning the stream allows chaining: cout << arr1 << arr2;
}