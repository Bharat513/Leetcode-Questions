class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = intervals.size();
        int i = 0;
        
        while(i < n && intervals[i][1] < newInterval[0]){
            ans.push_back(intervals[i++]);
        }

        vector<int> NewI = newInterval;
        while(i < n && intervals[i][0] <= newInterval[1]){
            NewI[0] = min(NewI[0], intervals[i][0]);
            NewI[1] = max(NewI[1], intervals[i][1]);
            i++;
        }
        ans.push_back(NewI);

        while(i < n){
            ans.push_back(intervals[i++]);
        }
        return ans;
    }
};