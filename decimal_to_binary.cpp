#include <iostream>
using namespace std;
int main()
{
    int binary;
    cin >> binary;

    int decimal = 0;
    int base = 1;

    while (binary > 0)
    {
        int last = binary % 10;
        decimal = decimal + last * base;
        base = base * 2;
        binary = binary / 10;
    }

    cout << "Decimal is :" << decimal << endl;
}