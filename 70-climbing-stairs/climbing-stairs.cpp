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
        //vector<int> dp(n + 1, 0);
        int prev1 = 1, prev2 = 1;
        for(int i = 2; i <= n; i++){
            //if(i == 0 || i == 1)dp[i] = 1;
            
                //int oneStep = dp[i - 1];
                //int twoStep = dp[i - 2];
                int temp = prev1;
                prev1 = prev2 + prev1;
                prev2 = temp; 
                //dp[i] = oneStep + twoStep;
            
        }
        return prev1;
    }
};