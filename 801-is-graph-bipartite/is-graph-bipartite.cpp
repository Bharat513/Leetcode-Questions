class Solution {
    bool dfs(vector<vector<int>>& graph, int node, int prevColor, vector<int>& vis){
        vis[node] = !prevColor;
        for(int i = 0; i < graph[node].size(); i++){
            int adjNode = graph[node][i];
            if(vis[adjNode] == -1){
                if(!dfs(graph, adjNode, !prevColor, vis)) return false;
            }
            else{
                if(vis[adjNode] != prevColor) return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);
        for(int i = 0; i < n; i++){
            if(vis[i] == -1){
                if(!dfs(graph, i, 0, vis)) return false;
            }
        }
        return true;
    }
};