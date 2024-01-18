class Solution {
    int helper(int n, vector<int> &dp){
        if(n == 0 || n == 1)return 1;
        if(dp[n] != -1) return dp[n];
        int oneStep = helper(n - 1, dp);
        int twoStep = helper(n - 2, dp);
        return dp[n] = oneStep + twoStep;
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        for(int i = 0; i <= n; i++){
            if(i == 0 || i == 1)dp[i] = 1;
            else{
                int oneStep = dp[i - 1];
                int twoStep = dp[i - 2];
                dp[i] = oneStep + twoStep;
            }
        }
        return dp[n];
    }
};