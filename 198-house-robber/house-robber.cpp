class Solution {
public:
    int rob(vector<int>& nums) {
         int n = nums.size();
        //vector<int> dp(n + 1, 0);
        //return helper(0, nums, dp);
        int nextTonext = 0;
        int next = nums[n - 1];
        //dp[n - 1] = nums[n - 1];
        int curr;
        for(int idx = n - 2; idx >= 0; idx--){
            
            int pick = nums[idx] + nextTonext;
            int notPick = next;
            curr = max(pick, notPick); 
            nextTonext = next;
            next = curr;
        }
        return next;
    }
};