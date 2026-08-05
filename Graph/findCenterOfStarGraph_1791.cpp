#include<iostream>
#include<vector>
using namespace std;
 class Solution {
    public:
      int findCenter(vector<vector<int>>&edges){
           vector<int>pair1 = edges[0];
            vector<int>pair2 = edges[1];
            if(pair1[0] == pair2[0] || pair1[0] == pair2[1]){
                return pair1[0];
            }
            else{
                return pair1[1];
            }
      }
};

int main(){
    Solution s ;
    vector<vector<int>>edges = {{1,2},{2,3},{4,2}} ;
    int ans = s.findCenter(edges) ;
    cout<<ans ;
}
