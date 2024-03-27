class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1)return 0;
        int ans = 0;
        int n = nums.size();
        int res = 1, right = 0, left = 0;
        while(right < n){
            res *= nums[right];
            while(res >= k){
                res /= nums[left++];
            }
            ans += (right - left + 1);
            right++;
        }
        return ans;
    }
};