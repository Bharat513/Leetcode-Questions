class Solution {
    bool palindrom(string s){
        int n = s.size();
        string revs1 = string(s.rbegin(), s.rend());
        for(int i = 0; i < n/2; i++){
            if(s[i] != revs1[i])return false;
        }
        return true;
    }
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 1; i + j <= n; j++){
                string subStr = s.substr(i, j);
                if(palindrom(subStr)) ans++;

            }
        }
        return ans;
    }
};