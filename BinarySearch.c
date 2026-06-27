#include <stdio.h>

int binarySearch(int a[], int size, int key)
{
    int start = 0, end = size - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (a[mid] == key)
            return mid;
        else if (a[mid] < key)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return -1;
}

void sortArray(int a[], int size)
{
    int temp;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main()
{
    int n, key, result;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    sortArray(a, n);

    printf("Enter the element to search: ");
    scanf("%d", &key);

    result = binarySearch(a, n, key);

    if (result != -1)
        printf("Element found at index %d .\n", result);
    else
        printf("Element not found .\n");

    return 0;
}
