#include <iostream>
using namespace std;
class Solution {
    public :
      int  gcdOfOddEvenSums(int n){
        return n ;
      }
};

int main(){
    Solution sol ;
    cout<<"Enter the number : ";
    int n ;
    cin>>n ;
    cout<<sol.gcdOfOddEvenSums(n);
    return 0 ;
}