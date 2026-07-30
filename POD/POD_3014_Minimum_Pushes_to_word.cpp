#include<iostream>
#include<string>
using namespace std;
class Solution {   
    public :
     int minPushes(string word){
        int n= word.length();
        int ans=0;
        for(int i =0;i<n;i++){
            ans +=(i/8)+1;
        }
        return ans;

     }
 };

 int main(){
    Solution s;
    string word;
    cin>>word;
    cout<<s.minPushes(word)<<endl;
    return 0;
 }
