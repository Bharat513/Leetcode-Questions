class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int maxi = 0;
        int n = points.size();
        for(int i = 1; i < n; i++){
            maxi = max(maxi, abs(points[i][0] - points[i-1][0]));
        }
        return maxi;
    }
};