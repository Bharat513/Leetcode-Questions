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
        vector<int> dp(n + 1, -1);
        return helper(n, dp);
    }
};