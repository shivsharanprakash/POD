#include<bits/stdc++.h>
using namespace std;
class Solution{
    int maximumLengthSubstring(string s){
        int ans = 0;
        int i =0;
        unordered_map<char,int> mp;
        for(int j =0;j<s.size();j++){
            mp[s[j]]++;
            while(mp[s[j]]>2){
                mp[s[i]]--;
                i++;
            }

            ans = max(ans,j-i+1);
        }
        return ans;

    }
};

int main(){
    Solution s;
    string str;
    cin>>str;
    cout<<s.maximumLengthSubstring(str);
}