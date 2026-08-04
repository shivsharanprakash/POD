#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> ans;

        for (int i = 0; i < nums.size() - 1; i++) {
            for (int x = nums[i] + 1; x < nums[i + 1]; x++) {
                ans.push_back(x);
            }
        }

        return ans;
    }
};

int main(){
    
    Solution s ;
    vector<int>nums = {1,3,5,7,9} ;
    vector<int>ans = s.findMissingElements(nums) ;

    for(int i =0;i<ans.size();i++){
        cout<<ans[i]<<" " ;
    }
}