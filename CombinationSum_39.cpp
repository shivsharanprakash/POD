#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

   void solve(int index,vector<int>&candidates ,int target , vector<int>& path ,vector<vector<int>>& ans){
    if(target==0){
        ans.push_back(path);
        return;
    }
    if(target<0)return ;

    for(int i = index ;i<candidates.size();i++){
        path.push_back(candidates[i]);
        solve(i+1,candidates,target-candidates[i],path,ans);
        path.pop_back();
    }
   }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans ;
        vector<int>path;
        solve(0,candidates,target,path,ans);
        return ans ;
    }
};

int main(){
    Solution sol;
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    vector<vector<int>> ans = sol.combinationSum(candidates,target);
    for(auto it:ans){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}