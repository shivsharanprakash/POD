#include<iostream>
#include<vector>
using namespace std ;
class ArrayConverter{
      public vector<vector<int>>&convert2Darray(vector<int>&original ,int m , int n){

            if(m*n!=original.size()){
                return new[0][0];
            }
            int index =0;
            int res[][]=new int[m][n];
            for(int i =0;i<m;i++){
                for(int j =0;j<n;j++){
                    res[i][j]=original[index];
                    index++;
                }
            }
      }
};
