#include<iostream>
#include<vector>
using namespace std;

class ZigZag {
    public :
        static const int MOD = 1000000007;

        int numberOfArrays(int n ,int l , int r ){
            int m = r-l+1;
            vector<vector<int>> dp(m+1,vector<int>(m+1,0));

            //initialize length 2 
            for(int b =1;b<=m;b++){
                dp[b][0]=b-1;
                dp[b][1]=1;

            }

            //already handled length 2, so start from length 3
            for(int len = 3;len<=n;len++){
                vector<int> prefixUp(m+1,0);
                vector<int> prefixDown(m+1,0);

                for(int i =1;i<=m;i++){
                    prefixUp[i] = (prefixUp[i-1]+dp[i][1])%MOD;
                    prefixDown[i] = (prefixDown[i-1]+dp[i][0])%MOD;
                }

                vector<vector<int>>ndp(m+1,vector<int>(2,0));

                for(int y=1;y<=m;y++){
                    ndp[y][0] = prefixUp[y-1];
                    ndp[y][1] = (prefixDown[m]-prefixDown[y]+MOD)%MOD;
                }
                dp =ndp;

            }

            long long ans = 0;
            for(int i =1;i<=m;i++){
                ans = (ans+dp[i][0]+dp[i][1])%MOD;
            }
            return ans;
        }
};

int main() {
    ZigZag zigzag;

    int n, l, r;

    cout << "Enter n l r : ";
    cin >> n >> l >> r;

    cout << "Number of ZigZag arrays = "
         << zigzag.numberOfArrays(n, l, r);

    return 0;
}