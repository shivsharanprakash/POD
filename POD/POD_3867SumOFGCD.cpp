#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
    public:
      long long getSumOfGDC(vector<int>&nums){
        int mx = 0;
        vector<int>prefixGCD(nums.size());
        for(int i =0;i<nums.size();i++){
            mx = max(mx,nums[i]);
            prefixGCD[i]=max(mx,nums[i]);
        }

        sort(prefixGCD.begin(),prefixGCD.end());
        long long ans = 0 ;
        int left = 0;
        int right = prefixGCD.size()-1;
        while(left<right){
            ans+=__gcd(prefixGCD[left],prefixGCD[right]);
            left++;
            right--;
        }

        return ans;
      }
};

int main (){
    Solution sol ;
    int n ;
    cout<<"Enter the size of the array : ";
    cin>>n ;
    vector<int>nums(n);
    cout<<"Enter the elements of the array : ";
    for(int i =0;i<n;i++){
        cin>>nums[i];
    }

    cout<<"Sum of GCD is : "<<sol.getSumOfGDC(nums)<<endl;
    return 0 ;
}