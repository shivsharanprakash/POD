#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    string shortestBeautifulSubString(string s,int k) {
        vector<int>pos;
        for(int i =0;i<s.size();i++){
            if(s[i]=='1'){
                pos.push_back(i);
            }
        }

        if(pos.size()<k){
            return "";
        }

        string ans ="";
        int bestLen = INT_MAX;
        for(int i =0;i+k-1<pos.size();i++){
            int start = pos[i];
            int end = pos[i+k-1];
            string cur = s.substr(start,end-start+1);
           if(cur.length() <bestLen || (cur.length() == bestLen && cur<ans)){
                ans = cur;
                bestLen = cur.length();
            }
        }
        return ans;

    }
};

int main(){
    Solution s;
    string str;
    int k;
    cin>>str>>k;
    string ans = s.shortestBeautifulSubString(str,k);
    cout<<ans;
}   