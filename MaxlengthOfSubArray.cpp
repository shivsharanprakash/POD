#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std ;


int logestSubarray(vector<int>&nums,int k){
    unordered_map<int,int>mp ;
    int currSum = 0 ;
    int maxLen = 0 ; 

    for (int i =0 ;i<nums.size();i++){
        currSum = currSum + nums[i];

        if(currSum ==k){
            maxLen = i+1;
        }

        int need = currSum - k ;

        if(mp.find(need)!=mp.end()){
            int len = i - mp[need];
            maxLen = max(maxLen,len);
        }

        if(mp.find(currSum)==mp.end()){
            mp[currSum]=i;
        }
    }

    return maxLen;
}