#include <iostream>
using namespace std;

class Test
{
public:
    int bitwiseCompliment(int n)
    {
        int m = n;

        int mask = 0;

        if (n == 0)
        {
            return 1;
        }

        while (m != 0)
        {
            mask = (mask << 1) | 1;
            m = m >> 1;
        }

        int ans = (~n) & mask;
        return ans;
    }
};

int main()
{

    Test t1;
    int n;
    cin >> n;
    int num = t1.bitwiseCompliment(n);
    cout << "output is : " << num << endl;
    return 0;
}