#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std ;
  
class Solution{
    public :
      int maxSubArrayLen(vector<int>&nums ,int k){
        int ans = 0;
        int i =0 ;
        unordered_map<int,int> mp;
        for(int j =0;j<nums.size();j++){
            mp[nums[j]]++;
            while(mp[nums[j]]>k){
                mp[nums[i]]--;
                i++;
            }

            ans = max(ans,j-i+1);
        }

        return ans;
     }
};


int main(){
    Solution s;
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i =0;i<n;i++){
        cin>>nums[i];
    }
    cout<<s.maxSubArrayLen(nums,k);
}

///#####################Optimal Solution ###############/////

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> counter;

        int result = 0, lo = 0, hi = 0;
        while (hi < nums.size()) {
            auto& c = counter[nums[hi]];
            if (c < k) {
                result = max(result, (hi + 1) - lo);
                c++;
            } else {
                c++;
                int out = nums[lo];
                counter[out]--;
                lo++;
                while (out != nums[hi]) {
                    out = nums[lo];
                    counter[out]--;
                    lo++;
                }
            }
            hi++;
        }
        return result;
    }
};
