#include<iostream>
#include<vector>
using namespace std ;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans ;
        for(int length = 2 ;length<=9;length++){
            for(int start = 1 ; start<=9;start++){
                int num =0;
                int digit = start ;
                bool valid = true ;
                for(int i =0;i<length;i++){
                    if(digit>9){
                        valid = false ;
                        break ;
                    }

                    num =num*10 + digit;
                    digit ++;
                }

            if(valid && num>=low && num<=high){
                ans.push_back(num);
            }

            }
        }
        return ans ;
    }
};
