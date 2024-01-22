class Solution {
    bool dfs(int node,vector<int> adj[],vector<int> &vis,vector<int>& pathvis,set<int>& st){
        vis[node]=1;
        st.insert(node);
        pathvis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,vis,pathvis,st)==true) return true; 
            }
            else if(pathvis[it]==true) {
                return true;
            }    
        }
        pathvis[node]=0;
        
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        //int m=graph[0].size();
        vector<int> adj[n];
        vector<int> indegree(n, 0);
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[graph[i][j]].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0)q.push(i);
        }
        set<int> st;

        while(!q.empty()){
            int Node=q.front();
	        q.pop();
	        st.insert(Node);
	        for(auto it:adj[Node]){
	            indegree[it]--;
	            if(indegree[it]==0){
	                q.push(it);
	            }
	        }
        }

        vector<int> topo(st.begin(), st.end());
        
        
        return topo;

    }
};