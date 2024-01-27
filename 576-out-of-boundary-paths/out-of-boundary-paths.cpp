class Solution {
    int mod = 1e9 + 7;
    int helper(int startRow, int startColumn, int m, int n, int maxMove, int moveCnt,                   vector<vector<vector<int>>>& dp){
        if(n == 0 && m ==0) return 0;
        if(moveCnt >= maxMove) return 0;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        if(dp[startRow][startColumn][moveCnt] != -1)return dp[startRow][startColumn][moveCnt];
        int ans = 0;
        for(int i = 0; i < 4; i++){
            int nr = startRow + dr[i];
            int nc = startColumn + dc[i];
            if(nr < 0 || nr >= m || nc < 0 || nc >= n) ans = (ans + 1)%mod;
            else{
                ans  = (ans + helper(nr, nc, m, n, maxMove, moveCnt + 1, dp)) % mod;
            }
        }
        return dp[startRow][startColumn][moveCnt] = ans;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(maxMove + 1, -1)));
        return helper(startRow, startColumn, m, n, maxMove, 0, dp);
    }
};