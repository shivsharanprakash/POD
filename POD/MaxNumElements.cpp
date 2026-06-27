#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    int maxNumOfElements(vector<int> &nums)
    {
        map<long long, int> freqMap;
        for (int el : nums)
        {
            freqMap[el]++;
        }

        int maxAns = 1;

        if (freqMap.find(1) != freqMap.end())
        {
            int count1 = freqMap[1];
            if (count1 % 2 == 0)
            {
                maxAns = max(maxAns, count1 - 1);
            }
            else
            {
                maxAns = max(maxAns, count1);
            }
        }

        for (auto const &[el, freq] : freqMap)
        {
            if (el == 1)
                continue;

            long long x = el;
            int count = 0;

            while (freqMap.find(x) != freqMap.end() && freqMap[x] > 0)
            {

                if (freqMap[x] >= 2)
                {
                    count += 2;
                }
                else if (freqMap[x] == 1)
                {
                    count += 1;
                    break;
                }

                if (x > 1e6)
                {
                    break;
                }

                x = x * x;
            }
            if (count % 2 == 0)
            {
                count--;
            }

            maxAns = max(maxAns, count);
        }
        return maxAns;
    }
};


int main()
{
    int n;

    cout << "Enter size: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    Solution obj;

    int ans = obj.maxNumOfElements(nums);

    cout << "Maximum elements = " << ans << endl;

    return 0;
}