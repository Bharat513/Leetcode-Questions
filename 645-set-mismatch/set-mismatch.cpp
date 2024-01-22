class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int sum = (n * (n + 1))/2;
        int arrSum = 0;
        unordered_set<int> st;
        int duplicateNum = -1;
        for(auto it : nums){
            arrSum += it;
            if(st.find(it) != st.end())duplicateNum = it;
            st.insert(it);
        }
        int secondNum = duplicateNum + (sum - arrSum);
        return {duplicateNum, secondNum};
    }
};