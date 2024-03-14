class Solution {
    private:
    int maxSumSubArray(vector<int>& nums, int goal){
        if(goal < 0) return 0;
        int n = nums.size();
        int i = 0, j = 0;
        int res = 0, sum = 0;
        while(j < n){
            sum += nums[j];

            while(i < n && sum > goal){
                sum -= nums[i++];
            }
            res += (j - i + 1);
            j++;
        }
        return res;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return maxSumSubArray(nums, goal) - maxSumSubArray(nums, goal - 1);
    }
};