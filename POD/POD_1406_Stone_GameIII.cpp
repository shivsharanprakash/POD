#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> dp;

    int solve(int i, vector<int>& stoneValue) {
        int n = stoneValue.size();

        if (i >= n)
            return 0;

        if (dp[i] != INT_MIN)
            return dp[i];

        int sum = 0;
        int ans = INT_MIN;

        for (int k = 0; k < 3 && i + k < n; k++) {
            sum += stoneValue[i + k];
            ans = max(ans, sum - solve(i + k + 1, stoneValue));
        }

        return dp[i] = ans;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        dp.assign(n, INT_MIN);

        int ans = solve(0, stoneValue);

        if (ans > 0)
            return "Alice";
        if (ans < 0)
            return "Bob";
        return "Tie";
    }
};



// ########### Optimal Solution ########

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int>dp(3,0);
        for(int i=n-1;i>=0;i--){
            int t1 = stoneValue[i]-dp[(i+1)%3];
            int t2 = INT_MIN;
            if(i+1<n) t2 = stoneValue[i]+stoneValue[i+1]-dp[(i+2)%3];
            int t3 = INT_MIN;
            if(i+2<n) t3 = stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]-dp[(i+3)%3];
            dp[i%3] =  max({t1,t2,t3});
        }
        int ans = dp[0];
        if(ans>0) return "Alice";
        else if(ans<0) return "Bob";
        else return "Tie";
    }
};