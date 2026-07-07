#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        auto cmp = [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        };

        sort(intervals.begin(), intervals.end(), cmp);

        int count = 1;
        int maxEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][1] <= maxEnd) {
                continue;  
            }

            maxEnd = intervals[i][1];
            count++;
        }

        return count;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals = {{1, 4}, {3, 6}, {2, 8}};
    int result = sol.removeCoveredIntervals(intervals);
    cout << "Number of remaining intervals: " << result << endl;
    return 0;
}