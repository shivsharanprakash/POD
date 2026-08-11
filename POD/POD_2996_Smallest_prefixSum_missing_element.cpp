#include<bits/stdc++.h>
using namespace std;
class Solution{
    public :
     int MissingInteger(vector<int>&nums){
        int sum =nums[0];
        for(int i =1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1){
                sum+=nums[i];
            }
            else{
                break;
            }
        }

        unordered_set<int> s(nums.begin(),nums.end());
        
        while(s.count(sum)){
            sum++;
        }

        return sum;
     }
};

int main(){
    Solution s;
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i =0;i<n;i++){
        cin>>nums[i];
    }
    cout<<s.MissingInteger(nums);
}   