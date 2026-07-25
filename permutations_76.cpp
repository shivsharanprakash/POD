#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void solve(vector<int> &nums, vector<bool> &visited, vector<int> &path, vector<vector<int>> &ans)
    {
        if (path.size() == nums.size())
        {
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (visited[i])
                continue;
            path.push_back(nums[i]);
            visited[i] = true;
            solve(nums, visited, path, ans);
            path.pop_back();
            visited[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int> & nums)
        {
            vector<vector<int>> ans;
            vector<bool> visited(nums.size(), false);
            vector<int> path;
            solve(nums, visited, path, ans);
            return ans;
        }
};


int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = sol.permute(nums);
    for (auto it : ans)
    {
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}