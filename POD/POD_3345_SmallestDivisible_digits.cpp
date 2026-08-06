#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    int smallestDivisible( int n , int k){
        while(true){
            int temp =n;
            int num =1;
            while(temp>0){
                num = num * (temp%10);
                temp = temp/10;
            }

            if(num%k==0){
                return n;
            }

            n++;
        }
    }
};

int main(){
    Solution s;
    int n,k;
    cin>>n>>k;
    cout<<s.smallestDivisible(n,k);
}