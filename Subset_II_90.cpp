#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {

public:

   void solve(int index ,vector<int>& nums,vector<int>& path,vector<vector<int>>& ans){

     ans.push_back(path);
     for(int i =index;i<nums.size();i++){
        if(i>index && nums[i]==nums[i-1])continue ;

        path.push_back(nums[i]);
        solve(i+1,nums,path,ans);
        path.pop_back();
    }
    
   }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans ;
        vector<int>path ;  
        sort(nums.begin(),nums.end());
        solve(0,nums,path,ans);
        return ans;
    }
};
    
int main(){
    Solution sol;
    vector<int> nums = {1,2,2};
    vector<vector<int>> ans = sol.subsets(nums);
    for(auto it:ans){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}