#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
    public :
     int maxProduct(int n ){
        string s = to_string(n);
        sort(s.rbegin(),s.rend());
          if (s.length() < 2)
            return 0;
        int max_prod = (s[0]-'0')*(s[1]-'0');
        return max_prod;
     }   
};


   int main(){
        Solution sol ;
        int n ;
        cout<<"Enter a number : ";
        cin>>n; 
        cout<<sol.maxProduct(n)<<endl;
        return 0 ;
     }
