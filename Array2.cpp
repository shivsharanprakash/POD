#include <iostream>
using namespace std;

int sum(int a[], int n)
{
    int add = 0;
    for (int i = 0; i < n; i++)
    {
        add = add + a[i];
    }
    return add;
}

int LinearSearch(int a[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int main()
{

    int size;
    int key;
    cout << "Enter size :" << endl;
    cin >> size;
    int a[100];
    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }

    cout << "sum of all elements is : " << sum(a, size) << endl;

    cout << "enter the element you wish to search : " << endl;
    cin >> key;

    int result = LinearSearch(a, size, key);
    if (result == -1)
    {
        cout << "the value not found !!!" << endl;
    }
    else
    {
        cout << "value " << key << " found at " << result+1 << " location" << endl;
    }

    return 0;
}