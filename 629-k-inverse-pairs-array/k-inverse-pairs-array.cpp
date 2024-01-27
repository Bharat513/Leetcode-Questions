class Solution {
    int v[1001][1001] = {0};
    
    int mod = 1000000007;
public:
    // int kInversePairs(int n, int k) {
    //     if(n==0 || k<0)return 0;
    //     if ( k==0)return 1;
    //     if(v[n][k] != 0) return v[n][k];
    //     int ans = 0;
    //     for(auto i = 0 ; i<=min(n-1,k) ; i++){
    //         ans = (ans+ kInversePairs(n-1,k-i))%mod;
    //     }
        
    //     return v[n][k] = ans;
    // }

     int kInversePairs(int n, int k) {
        if(n==0 || k<0)return 0;
        if ( k==0)return 1;
        vector<vector<int>> dp(n + 1, vector<int> (k + 1, 0));
        for(int i = 1; i <= n; i++)dp[i][0] = 1;
        
        for(int i = 1; i <= n; i++){
            for(int l = 1; l <= k; l++ ){
                for(int j = 0; j <= min(i - 1, l); j++){
                    dp[i][l] = (dp[i][l]+ dp[i-1][l - j])%mod;
                }
            }
        }
        return dp[n][k];
    }

     
};