class Solution {
    bool findPalindrome(string s){
        int n = s.size();
        for(int i = 0; i <= n/2; i++){
            if(s[i] != s[n - 1 - i])return false;
        }
        return true;
    }

public:
    string firstPalindrome(vector<string>& words) {
        for(auto it : words){
            if(findPalindrome(it))return it;
        }
        return "";
    }
};