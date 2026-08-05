#include<iostream>
#include<vector>
using namespace std ;
class Solution{
    public :
       void Dfs(int src ,vector<vector<int>>&adj,vector<bool>&visited){
             visited[src] = true ;
             cout<<src<<" " ;
             for(int neighbor : adj[src]){
                 if(!visited[neighbor]){
                     Dfs(neighbor,adj,visited) ;
                 }
             }
             
       }
};

int main()
{
    int V = 6;

    vector<vector<int>> adj(V);

    adj[0]={1,2};
    adj[1]={0,3,4};
    adj[2]={0,5};
    adj[3]={1};
    adj[4]={1};
    adj[5]={2};

    vector<bool> visited(V,false);

    Solution sol;
    sol.Dfs(0,adj,visited);
}