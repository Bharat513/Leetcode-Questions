class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(auto it : nums){
            mp[it]++;
        }
        int maxi = 0, cnt = 0;
        for(auto it : mp){
            if(maxi < it.second){
                maxi = it.second;
                cnt = it.second;
            }else if(maxi == it.second){
                cnt += it.second;
            }
        }
        return cnt;
    }
};