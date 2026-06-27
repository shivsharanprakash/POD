#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std ;

bool containsDuplicate(vector<int>&nums){
    unordered_map<int,int>mp ;

   for(int i =0;i<nums.size();i++){
        if(mp.find(nums[i])!=mp.end()){
            return true ;
        }
        mp[nums[i]] = i ;
   }
   return false ;
}

int main (){
    vector<int>nums; 
   int size; 
   cout<<"Enter the size of the array : ";
   cin>>size;

   for(int i = 0 ;i<size ; i ++){

    int x ; 
    cout<<"Enter the "<<i<< "element : ";
    cin>>x;
    nums.push_back(x);

   }
   
   if(containsDuplicate(nums)){
    cout<<"Duplicate element exist in array "<<endl;
   }
   else{
    cout<<"No duplicate element exist in array "<<endl;
   }
}