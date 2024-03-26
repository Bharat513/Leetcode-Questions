class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int number = 1;
        for(auto num : nums){
            if(number == num)number++;
            else if(number < num)return number;

        }
        return number;
    }
};