class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int m = flights.size();
        vector<pair<int, int>> adj[n];
        for(int i = 0; i < m; i++){
            int from = flights[i][0];
            int to = flights[i][1];
            int price = flights[i][2];
            adj[from].push_back({to, price});
        }

        queue<pair<int, pair<int, int>>>q;
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        q.push({0, {src, 0}});
        while(!q.empty()){
            int step = q.front().first;
            int middleNode = q.front().second.first;
            int midDist = q.front().second.second;
            q.pop();

            if(step>k)continue;
            for(auto it : adj[middleNode]){
                int newDist = midDist + it.second;
                int newNode = it.first;
                if(dist[newNode] > newDist && step <= k){
                   dist[newNode] =  newDist;
                   q.push({step + 1, {newNode, newDist}});
                }
            }
        }
        if(dist[dst]==1e9) return -1;
        
        return dist[dst];
    }
};