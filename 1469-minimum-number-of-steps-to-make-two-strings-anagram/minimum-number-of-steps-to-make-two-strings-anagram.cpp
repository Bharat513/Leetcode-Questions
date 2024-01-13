class Solution {
public:
    int minSteps(string s, string t) {
        int n = s.size();
        unordered_map<char, int> mp;
        for(int i = 0; i < n; i++){
            mp[s[i]]++;
            mp[t[i]]--;
        }

        int cnt = 0;
        for(auto it : mp){
            cnt += abs(it.second);
        }

        return cnt / 2;
    }
};