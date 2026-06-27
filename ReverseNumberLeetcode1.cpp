#include <iostream>
using namespace std;
class Test
{
public:
    int reverse(int x)
    {
        int ans = 0;
        while (x != 0)
        {
            int digit = x % 10;
            if ((ans > INT32_MAX / 10) || (ans < INT32_MIN / 10))
            {
                return 0;
            }

            ans = (ans * 10) + digit;
            x = x / 10;
        }
        return ans;
    }
};

int main()
{
    Test t;
    int n;
    cin >> n;
    int num = t.reverse(n);
    cout << num << endl;
    return 0;
}