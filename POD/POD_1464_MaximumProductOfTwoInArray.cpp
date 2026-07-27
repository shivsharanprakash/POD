#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    
    public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.size() < 2)
            return 0;

        return (nums[nums.size() - 1] - 1) * (nums[nums.size() - 2] - 1);
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << "Maximum product of two elements in the array: " << sol.maxProduct(nums) << endl;
    return 0;
}