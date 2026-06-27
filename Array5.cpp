#include <iostream>
using namespace std;

bool uniqueNUm(int a[], int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ a[i];
    }
    
    if(ans!=0){
        return false;
    }else{
        return true;
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

    int num = uniqueNUm(a, size);
    if (num == 0)
    {
        cout << "not found unique num .";
    }
    else
    {
        cout << "unique number is : " << num << endl;
    }

    return 0;
}
