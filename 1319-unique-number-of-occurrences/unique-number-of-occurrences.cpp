class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_set<int> st;
        unordered_map<int, int> mp;
        for(auto it : arr){
            mp[it]++;
        }
        for(auto it : mp){
            if(st.find(it.second) != st.end()) return false;
            st.insert(it.second);
        }
        return true;
    }
};