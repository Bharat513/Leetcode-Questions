class Solution {
    int helper(vector<int>& tasks, int idx, vector<int>& dp){
        int n = tasks.size();
        if(idx >= n) return 0;
        if(idx >= n-1) return 1e9;
        if(dp[idx] != -1) return dp[idx];
        int twotask = 1e9, threeTask = 1e9;
        if(idx < n -1){
            if(tasks[idx] == tasks[idx + 1]){
                twotask = 1 + helper(tasks, idx + 2, dp);
            }
        }
        if(idx < n - 2){
            if(tasks[idx] == tasks[idx + 1] && tasks[idx] == tasks[idx + 2]){
                threeTask = 1 + helper(tasks, idx + 3, dp);
            }
        }
        return dp[idx] = min(twotask, threeTask);
    }
public:
    int minimumRounds(vector<int>& tasks) {
        sort(tasks.begin(), tasks.end());
        int n = tasks.size();
        vector<int> dp(n + 1, -1);
        int ans = helper(tasks, 0, dp);
        if(ans >= 1e9) return -1;
        return ans;
    }
};