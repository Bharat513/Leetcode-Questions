class Solution {
    int helper(int n, int lastNum, vector<int> &dp){
        
        if(n == 0) return 0;
        if(n < 0) return 1e9;
        if(lastNum * lastNum > n) return 1e9;

        if(dp[n] != -1) return dp[n];
        int end = sqrt(n);
        int ans = 1e9;
        for(int i = lastNum; i <= end; i++){
            int pick = 1 + helper(n - i * i, i, dp);
            int notPick = helper(n, i + 1, dp);
            ans = min(ans, min(pick, notPick));
        }
        return dp[n] = ans;
    }
public:
    int numSquares(int n) {
        vector<int> dp(n + 2, 1e9);
        dp[0] = 0;
        dp[1] = 1;
        for(int j = 2; j <= n; j++){
            int end = sqrt(j);
            int ans = 1e9;
            for(int i = 1; i <= end; i++){
                int pick = 1 + dp[j - i * i];
                int notPick = dp[j];
                ans = min(ans, min(pick, notPick));
            }
            dp[j] = min (dp[j], ans);
        }
        return dp[n];
    }
};