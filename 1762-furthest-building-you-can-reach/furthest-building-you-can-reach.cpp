class Solution {
    int helper(vector<int>& heights, int bricks, int ladders, int idx, vector<vector<vector<int>>> &dp){
        int n = heights.size();
        if(idx == n - 1)return n - 1;
        if(dp[idx][bricks][ladders] != -1) return dp[idx][bricks][ladders];
        if(ladders <= 0 && bricks < heights[idx + 1] - heights[idx])return idx;
        if(heights[idx + 1] - heights[idx] <= 0) return dp[idx][bricks][ladders] = helper(heights, bricks, ladders, idx + 1, dp);
        else{
            int ladder = idx, brick = idx;
            if(ladders)ladder = helper(heights, bricks, ladders - 1, idx + 1, dp);
            if(bricks >= heights[ idx + 1] - heights[idx]) brick = helper(heights, bricks - (heights[idx + 1] - heights[idx]) , ladders, idx + 1, dp);

            return dp[idx][bricks][ladders] = max(ladder, brick);
        }
    }
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n - 1; ++i) {
            int diff = heights[i + 1] - heights[i];
            if (diff > 0) {
                if (pq.size() < ladders) {
                    pq.push(diff);
                } else {
                    if (pq.empty() || pq.top() >= diff) {
                        bricks -= diff;
                    } else {
                        int poll = pq.top(); pq.pop();
                        pq.push(diff);
                        bricks -= poll;
                    }
                    if (bricks < 0) return i;
                }
            }
        }
        return n - 1;
    }
};