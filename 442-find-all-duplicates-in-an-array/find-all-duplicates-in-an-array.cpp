class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        for(int i = 0; i < n; i++){
            while(nums[i] != i + 1){
                if(nums[i] == nums[nums[i] - 1]){
                    st.insert(nums[i]);
                    break;
                }
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        vector<int> ans(st.begin(), st.end());
        return ans;
    }
};