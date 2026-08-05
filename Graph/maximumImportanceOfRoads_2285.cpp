#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;
class Solution{
    public:
      long long maximumImportance(int n, vector<vector<int>>& roads){
          vector<int>degree(n) ;
          for(int i=0;i<roads.size();i++){
              degree[roads[i][0]]++ ;
              degree[roads[i][1]]++ ;
          }
          sort(degree.begin(),degree.end()) ;
          long long ans = 0 ;
          for(int i=0;i<n;i++){
              ans += (long long)degree[i]*(i+1) ;
          }
          return ans ;
      }
};

int main(){
    Solution s ;
    int n = 5 ;
    vector<vector<int>>roads = {{0,1},{0,2},{1,2},{1,3},{1,4}} ;
    long long ans = s.maximumImportance(n,roads) ;
    cout<<ans ;
}