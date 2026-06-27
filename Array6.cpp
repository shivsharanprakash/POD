#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int> &arr)
{
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        ans = ans ^ arr[i];
    }

    for (int i = 1; i < arr.size(); i++)
    {
        ans = ans ^ i;
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the number of elements (n+1): ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " numbers (from 1 to " << n - 1 << ", with one duplicate):" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int duplicate = findDuplicate(arr);
    cout << "Duplicate element is: " << duplicate << endl;

    return 0;
}



class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>result;
        for(int i =0;i<nums1.size();i++){
                 int element =nums1[i];

            for(int j =0;j<nums2.size();j++){
                if(element==nums2[j]){
                    bool isAlready=false;
                    for(int k=0;k<result.size();k++){
                        if(result[k]==element){
                            isAlready=true;
                            break;
                    
                        }
                    }
                    if(!isAlready){
                          result.push_back(nums1[i]);
                    }
                     
                        nums2[j]=-1e9;
                        break;
                     
                    
                }
            }
        }
        return result;
    }
};