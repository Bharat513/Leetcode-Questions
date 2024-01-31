class DisjointSet{
    vector<int> parent, rank, size;
    public:
    DisjointSet(int V){
        parent.resize(V + 1);
        rank.resize(V + 1, 0);
        size.resize(V + 1, 1);
        for(int i = 0; i <= V; i++){
            parent[i] = i;
        }
    }
    
    int FindUparent(int node){
        if(node == parent[node])return node;
        return parent[node] = FindUparent(parent[node]);
    }
    
    void unionByRank(int u, int v){
        int u_parent = FindUparent(u);
        int v_parent = FindUparent(v);
        if(u_parent == v_parent) return;
        if(rank[u_parent] > rank[v_parent]){
            parent[v_parent] = u_parent;
        }
        if(rank[u_parent] < rank[v_parent]){
            parent[u_parent] = v_parent;
        }else{
            parent[u_parent] = v_parent;
            rank[u_parent]++;
        }
        
    }
    
    void unionBySize(int u, int v){
        int u_parent = FindUparent(u);
        int v_parent = FindUparent(v);
        if(u_parent == v_parent) return;
        
        if(size[u_parent] > size[v_parent]){
            parent[v_parent] = u_parent;
            size[u_parent] += size[v_parent];
        }
        else{
            parent[u_parent] = v_parent;
            size[v_parent] += size[u_parent];
        }
    }
      
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DisjointSet ds(n + 1);
        unordered_map<string, int> mergeNode;
        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                if(mergeNode.find(accounts[i][j]) == mergeNode.end()){
                    mergeNode[accounts[i][j]] = i;
                }else{
                    ds.unionBySize(i, mergeNode[accounts[i][j]]);
                }
            }
        }

        vector<string> mail[n];
        for(auto it : mergeNode){
            int node = ds.FindUparent(it.second);
            string mailId = it.first;
            mail[node].push_back(mailId);

        }
         vector<vector<string>> ans;
        for(int i = 0; i < n; i++){
            
            if(mail[i].size() == 0)continue;
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            sort(mail[i].begin(), mail[i].end());
            for(auto it : mail[i])temp.push_back(it);

            ans.push_back(temp);

        }
        return ans;

    }
};