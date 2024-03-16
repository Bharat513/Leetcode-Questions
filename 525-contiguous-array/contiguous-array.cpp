class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        int diff = 0;
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++){
            if(nums[i] == 1) diff++;
            else diff--;
            if(diff == 0) maxi = i + 1;
            else if(mp.find(diff) != mp.end()){
                maxi = max(maxi, i - mp[diff]);
            }
            if(mp.find(diff) == mp.end()){
                mp[diff] = i;
            }
        }
        return maxi;
    
    }
};