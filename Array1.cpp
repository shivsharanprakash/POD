#include <iostream>
using namespace std;
int getMax(int a[], int n)
{
    int maxi = INT32_MIN;
    for (int i = 0; i < n; i++)
    {
        // if (a[i] > max)
        // {
        //     max = a[i];
        // }
        maxi=max(maxi,a[i]);
        
    }
    return maxi;
}

int getMin(int a[], int n)
{
    int mini = INT32_MAX;
    for (int i = 0; i < n; i++)
    {
        // if (a[i] < min)
        // {
        //     min = a[i];
        // }
        mini=min(mini,a[i]);
    }
    return mini;
}

int main()
{
    int size ;
    cout<<"Enter the size of array : ";
    cin>>size;
    int num[100];

    for(int i =0;i<size;i++){
        cin>>num[i];
    }

    cout<<"Maximum value is :"<<getMax(num,size)<<endl;
    cout<<"Minimum value is :"<<getMin(num,size)<<endl;

 return 0;
}