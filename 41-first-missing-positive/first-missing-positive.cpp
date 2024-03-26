class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<int> filledNum(n+1, 0);
        
        for(auto num : nums){
            if(num > 0 && num <= n)filledNum[num] = 1;

        }
        for(int i = 1; i < n + 1; i++){
            if(!filledNum[i])return i;
        }
        return n + 1;
    }
};