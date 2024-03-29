class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans (n, -1);
        int positive = 0, neg = 1;
        for(int i = 0; i < n; i++){
            if(nums[i] < 0){
                ans[neg] = nums[i];
                neg += 2;
            }else{
                ans[positive] = nums[i];
                positive += 2;
            }
        }
        return ans;

    }
};