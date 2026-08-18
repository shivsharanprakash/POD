#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
      int LargestInteger(vector<int>nums,int k){
        int n = nums.size();
        vector<int>count(51,0);
        for(int i = 0 ;i<n-k;i++){
            bool seen[51] = {};
            for(int j = i;j<i+k;j++){
                seen[nums[j]] = true;
            }

            for(int x =0;x<=50;x++){
                if(!seen[x]){
                    count[x]++;
                }
            }

            for(int x =0;x<=50;x++){
                if(count[x] == n-k){
                    return x;
                }
            }
        }

        return -1 ;
      }
};

int main(){
    Solution s;
    int n,k;
    cin>>n>>k;
    vector<int>nums(n);
    for(int i =0;i<n;i++){
        cin>>nums[i];
    }
    cout<<s.LargestInteger(nums,k);
}   
