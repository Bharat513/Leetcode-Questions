class Solution {
    void dfs(vector<int> adj[], vector<int> &vis, int node){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it])dfs(adj, vis, it);
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int E = connections.size();
        if(E + 1 < n) return -1;

        vector<int> adj[n];
        for(int i = 0; i <E; i++){
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cnt = 0;
        vector<int> vis(n, 0);

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                cnt++;
                dfs(adj, vis, i);
            }
        }
        return cnt - 1;
    }
};