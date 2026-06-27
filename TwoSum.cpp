#include<iostream>
#include <unordered_map>
#include<vector>
using namespace std ;

vector<int>twosum(vector<int>&nums ,int target){
    unordered_map<int,int>map;

    for(int i =0;i<nums.size();i++){
        int need = target - nums[i];

        if(map.find(need)!=map.end()){
            return{map[need],i};
        }

        map[nums[i]]=i;
    }
    return {};
}

int main (){
   vector<int>nums; 
   int target,size; 
   cout<<"Enter the size of the array : ";
   cin>>size;

   for(int i = 0 ;i<size ; i ++){

    int x ; 
    cout<<"Enter the "<<i<< "element : ";
    cin>>x;
    nums.push_back(x);

   }
   cout<<"Enter target : ";
   cin>>target;

    vector<int>ans = twosum(nums,target);
    if(ans.size()==0){
        cout<<"No such pair exist "<<endl;
    }
    else{
        cout<<"Pair found at index : "<<ans[0]<<" and "<<ans[1]<<endl;
    }
   

}