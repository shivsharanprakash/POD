#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std ;

int subarraysum(vector<int> &nums,int k ){
    unordered_map<int ,int> mp ;
    mp[0]=1;
    int currentSum=0;
    int count =0;
    for(int num :nums){
        currentSum = currentSum + num;
        int need = currentSum - k;

        if(mp.find(need) !=mp.end()){
            count = count + mp[need];
        }

        mp[currentSum]++;

    }

    return count;
}

int main (){
    vector<int>nums ;
    int n ;
    cout<<"Enter the number of elements in array : ";
    cin>>n;
    for(int i = 0 ;i<n ;i++){
        int x ;
        cout<<"Enter"<<i<<"th"<<"element";
        cin>>x;
        nums.push_back(x);
    }
    int k;
    cout<<"Enter required sum : ";
    cin>>k ;
    cout<<subarraysum(nums,k);
    return 0 ;
}