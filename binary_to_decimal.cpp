#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    string binary = "";

    if (n == 0)
    {
        binary = "0";
    }

    while (n > 0)
    {
        int bit = n % 2;
        binary = to_string(bit) + binary;
        n = n / 2;
    }

    cout << "Binary is :" << binary << endl;
}