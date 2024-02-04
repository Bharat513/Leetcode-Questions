class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        for(auto it : t){
            mp1[it]++;
        }
        int mini = 1e9, start = -1;
        int count = mp1.size();
        int i = 0, j = 0;
        while(j < n){
            char ch = s[j];
            if(mp1[ch]){
                mp2[ch]++;
                if(mp1[ch] == mp2[ch]){
                    count--;
                }
            }
            if(count > 0)j++;
            else{

                while(count == 0){
                    if(mini > j - i + 1){
                        start = i;
                        mini = j - i + 1;
                    }
                    char ch1 = s[i];
                    if(mp1[ch1]){
                        mp2[ch1]--;
                        if(mp1[ch1] - mp2[ch1] == 1){
                            count++;
                        }
                    }
                    i++;

                }
                j++;
            }
            
           
        }
        if(start == -1 || mini == 1e9) return "";
        return s.substr(start, mini);
    }
};