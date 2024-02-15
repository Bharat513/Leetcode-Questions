class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> sum(n, 0);
        sum[0] = nums[0];
        sum[1] = sum[0] + nums[1];
        int idx = -1;
        for(int i = 2; i < n; i++){
            if(nums[i] < sum[i - 1])idx = i;

            
            sum[i] = sum[i - 1] + nums[i];
        }
        if(idx == -1)return -1;
        else return sum[idx];


    }
};