class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if(st.find(endWord) == st.end()) return 0;
        queue<pair<string, int>> q;
        int cnt = 0;
        q.push({beginWord, 1});
        st.erase(beginWord);
        while(!q.empty()){
            string word = q.front().first;
            int currCnt = q.front().second;
            int len = word.size();
            q.pop();
            for(int i = 0; i < len; i++){
                string newWord = word;
                for(int j = 0; j < 26; j++){
                    char newChar = 'a' + j;
                    newWord[i] = newChar;
                    if(newWord == endWord) return currCnt + 1;
                    if(st.find(newWord) != st.end()){
                        q.push({newWord, currCnt + 1});
                        st.erase(newWord);
                    }
                }
            }
            
        }
        return 0;

    }
};