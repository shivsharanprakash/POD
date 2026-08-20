#include<iostream>
#include<vector>
using namespace std ;

class solution{
    public :
       vector<int>inserElement(vector<int>&nums){
            int i = 0;
            int j = 1;

            if(nums.size()==2){
                return nums;
            }

            while(j <nums.size()-1){
                if(nums[i] >nums[j]){
                    swap(nums[j],nums[j+1]);
                    j++;
                    i++;
                }else{
                    j++;
                }
            }

            return nums ;
       }
};


int main(){
    solution s;
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i =0;i<n;i++){
        cin>>nums[i];
    }

    vector<int>ans = s.inserElement(nums);
    for(int i =0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
