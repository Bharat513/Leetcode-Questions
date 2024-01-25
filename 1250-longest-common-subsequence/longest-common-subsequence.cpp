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
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = lcs(0, 0, text1, text2, dp);
        return ans;
    }
};