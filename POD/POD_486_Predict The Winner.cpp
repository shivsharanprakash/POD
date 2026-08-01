#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public :

      int solve(vector<int>& nums,int i,int j,vector<vector<int>>& dp){
          if(i>j) return 0;
          if(dp[i][j]!=-1) return dp[i][j];
          int left=nums[i]-solve(nums,i+1,j,dp);
          int right=nums[j]-solve(nums,i,j-1,dp);
          return dp[i][j]=max(left,right);
      }
      bool predictTheWinner(vector<int>& nums){
          int n=nums.size();
          vector<vector<int>> dp(n,vector<int>(n,-1));
          return solve(nums,0,n-1,dp)>=0;

      }
};


int main(){
    Solution s;
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<s.predictTheWinner(nums)<<endl;
    return 0;
}