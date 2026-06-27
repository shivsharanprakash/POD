#include<iostream>
#include<vector>
using namespace std;

vector<int> astroidCollision(vector<int>&astroids){
    vector<int> ans ;
    for(int i =0;i<astroids.size();i++){
        if(ans.empty() || astroids[i]>0){
            ans.push_back(astroids[i]);
        }else{
            while(!ans.empty() && ans.back()>0 && ans.back()<abs(astroids[i])){
                ans.pop_back();
            }
            if(ans.empty() || ans.back()<0){
                ans.push_back(astroids[i]);
            }else if(ans.back() == abs(astroids[i])){
                ans.pop_back();
            }else{
                continue;
            }
        }
    }
    return ans;
}

int main(){
    vector<int> astroids = {5,10,-5};
    vector<int> ans = astroidCollision(astroids);
    cout<<"Astroids after collision : ";
    for(int i =0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
