#include <iostream>
using namespace std;

int UniqueValue(int a[], int size, int un[])
{
    int k = 0;
    for (int i = 0; i < size; i++)
    {
        int isunique = 1;
        for (int j = 0; j < i; j++)
        {

            if (un[j] == a[i])
            {
                isunique = 0;
                break;
            }
        }
        if (isunique)
        {
            un[k] = a[i];
            k++;
        }
    }
    return k;
}

int main()
{
    int size;
    cin >> size;
    int arr[100];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int un[100];
    int count = UniqueValue(arr, size, un);
    cout << "Duplicate array is  : " << endl;
    for (int k = 0; k < count; k++)
    {
        cout << un[k] << endl;
    }

    return 0;
}