class Solution {
    void djisktra(vector<pair<int, int>> adj[], int k, vector<int> &dist, int n){
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        dist[k] = 0; 
        while(!pq.empty()){
            int distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                int nodeDist = it.second;
                int adjNode = it.first;
                
                if(distance + nodeDist < dist[adjNode]){
                    dist[adjNode] = distance + nodeDist;
                    pq.push({distance + nodeDist, adjNode});
                }
            }
        }
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n];
        for(auto it : times){
            adj[it[0] - 1].push_back({it[1] - 1, it[2]});
        }
        vector<int> dist(n, 1e9);
        djisktra(adj, k - 1, dist, n);
        int ans = 0;
        for(auto it : dist){
            ans = max(ans, it);
        }
        return ans == 1e9 ? -1 : ans;
    }
};