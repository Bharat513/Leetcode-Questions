class Solution {
    int helper(int idx, vector<string>& arr, unordered_set<int> st){
        int n = arr.size();
        if(idx >= n) return 0;

        int pick = 0, notPick = 0;

        notPick = helper(idx + 1, arr, st);

        int flag = true;
        
        for(auto it : arr[idx]){
            if(st.find(it) != st.end()){
                flag = false;
                break;
            }
        }

        sort(arr[idx].begin(), arr[idx].end());
        for(int i = 1; i < arr[idx].size(); i++){
            if(arr[idx][i] == arr[idx][i - 1]){
                flag = false;
                break;
            }
        }
        if(flag){
            for(auto it : arr[idx]){
                st.insert(it);
            }
            pick = arr[idx].size() + helper(idx + 1, arr, st);
        }
        return max(pick, notPick);
        


    }
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        unordered_set<int> st;

        return helper(0, arr, st);

    }
};