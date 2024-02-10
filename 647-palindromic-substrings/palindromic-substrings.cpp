class Solution {
    // bool palindrom(string s){
    //     int n = s.size();
    //     string revs1 = string(s.rbegin(), s.rend());
    //     for(int i = 0; i < n/2; i++){
    //         if(s[i] != revs1[i])return false;
    //     }
    //     return true;
    // }
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            int left = i, right = i;
            while(left >= 0 && right < n){
                if(s[left] == s[right]){
                    left--, right++;
                    ans++;
                }else break;
            }

            left = i, right = i + 1;
            while(left >= 0 && right < n){
                if(s[left] == s[right]){
                    left--, right++;
                    ans++;
                }else break;
            }
        }
        return ans;
    }
};