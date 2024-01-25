class Solution {

    int lcs(int idx1, int idx2, string &text1, string &text2, vector<vector<int>> &dp ){
        int n = text1.size();
        int m = text2.size();
        if(idx1 >= n || idx2 >= m){
            return 0;
        }

        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

        int match = 0;
        if(text1[idx1] == text2[idx2]){
            match = 1 + lcs(idx1 + 1, idx2 + 1, text1, text2, dp);
        }
        int notMatch = max(lcs(idx1 + 1, idx2, text1, text2, dp), lcs(idx1, idx2 + 1, text1, text2, dp));
        return dp[idx1][idx2] = max(match, notMatch);
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
       

        for(int i = 0; i< n; i++){
            dp[i][m] = 0;
        }
        for(int i = 0; i< m; i++){
            dp[n][i] = 0;
        }
        for(int idx1 = n - 1; idx1 >= 0 ; idx1--){
            for(int idx2 = m - 1; idx2 >= 0; idx2--){
                int match = 0;
                if(text1[idx1] == text2[idx2]){
                    match = 1 + dp[idx1 + 1][idx2 + 1];
                }
                int notMatch = max(dp[idx1 + 1][idx2], dp[idx1][idx2 + 1]);
                dp[idx1][idx2] = max(match, notMatch);
            }
        }
        return dp[0][0];
    }
};