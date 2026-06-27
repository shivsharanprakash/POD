#include<iostream>
#include<vector>
using namespace std ;

vector<int>productExceptSelf(vector<int>&nums){
    int n = nums.size();
    vector<int>ans(n,1);

    for(int i =1 ; i<n;i++){
        ans[i] = ans[i-1] * nums[i-1];
    }

    int suffix =1 ; 
    for(int i =n-1;i>=0;i--){
        ans[i] = ans[i] * suffix ;
        suffix = suffix * nums[i];
    }
    return ans;
}

int main(){
    vector<int>nums;
    int n ;
    cout<<"Enter the number of elements in array : ";
    cin>>n;
    for(int i = 0 ;i<n ;i++){
        int x ;
        cout<<"Enter"<<i<<"th"<<"element";
        cin>>x;
        nums.push_back(x);
    }

    vector<int>ans = productExceptSelf(nums);
    cout<<"Product of array except self is : "<<endl;
    for(int i =0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}