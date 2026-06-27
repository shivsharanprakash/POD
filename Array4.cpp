#include <iostream>
using namespace std;

void swapAlternate(int a[], int n)
{
    for (int i = 0; i < n; i += 2)
    {
        if (i + 1 < n)
        {
            swap(a[i],a[i+1]);
        }
    }
}

int main()
{

    int size;
    cin >> size;
    int a[100];
    cout << "Enter elements : ";
    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }

    swapAlternate(a, size);
    cout<<"Swapped array : ";
    for (int i = 0; i < size; i++)
    {
        cout << a[i]<<" ";
    }
    return 0;
}



