class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        if(n1 != n2) return false;
        unordered_map<char, int> mp1, mp2;
        for(int i = 0; i < n1; i++){
            mp1[word1[i]]++;
            mp2[word2[i]]++;
        }
        if(mp1.size() != mp2.size()) return false;
        unordered_map<char, int> mp3, mp4;
        for(auto it : mp1){
            if(mp2.find(it.first) == mp2.end()) return false;
            mp3[it.second]++;
        }
        for(auto it : mp2){
            mp4[it.second]++;
        }
        for(auto it : mp3){
            if(mp4.find(it.first) == mp4.end()) return false;
            else if(it.second != mp4[it.first]) return false;
        }
        return true;
    }
};