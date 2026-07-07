#include<iostream>
#include<string>
#include<vector>
using namespace std;

// class Solution {
// public:
//     long long sumAndMultiply(int n) {
//         long long sum = 0 ;
//         string str  = to_string(n) ;
//         string newStr = "" ;
//         for(int i =0;i<str.length();i++){
//             if(str[i]!='0'){
//                 newStr += str[i] ;
//                 sum += (str[i]-'0') ;
//             }
//         }

//         if(newStr.length() == 0){
//             return 0 ;
//         }else{
//             long long product  = stoi(newStr) ;   
//             return sum * product ;

//         }

//     }
// };



class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0 ;
        int sum =0;
        int product = 1 ;
        vector<int> digits ;
       
        while(n>0){
            int digit = n%10 ;
            if(digit!=0){
                sum += digit ;
                digits.push_back(digit) ;
            }
            n /= 10 ;
        }

        if (digits.empty())
            return 0;

        for (int i = digits.size() - 1; i >= 0; i--) {
            product = product * 10 + digits[i];
        }

        return sum * product;

    }
};

int main(){
    Solution sol ;
    int n;
    cin>>n;
    long long ans = sol.sumAndMultiply(n) ;
    cout<<ans<<endl ;

    return 0;
}
