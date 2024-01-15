class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n = matches.size();
        unordered_map<int, int> loser;
        unordered_set<int> st;
        for(int i = 0; i < n; i++){
            st.insert(matches[i][0]);
            st.insert(matches[i][1]);
            loser[matches[i][1]]++;
        }
        vector<vector<int>> ans;
        vector<int> lose, win;
        for(auto it : st){
            if(loser[it] == 0){
                win.push_back(it);
            }else if(loser[it] == 1){
                lose.push_back(it);
            }
        }
        
        sort(lose.begin(), lose.end());
        sort(win.begin(), win.end());
        ans.push_back(win);
        ans.push_back(lose);
        return ans;

    }
};