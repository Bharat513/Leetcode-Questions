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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int m = stones[0].size();
        int maxRow = 0, maxCol = 0;
        for(auto it : stones){
            maxRow = max(it[0], maxRow);
            maxCol = max(maxCol, it[1]);
        }
        DisjointSet ds(maxRow + maxCol + 1);

        unordered_map<int, int> stonePos;
        for(auto it : stones){
            int row = it[0];
            int col = maxRow + it[1] + 1;
            ds.unionBySize(row, col);
            stonePos[row] = 1;
            stonePos[col] = 1;
        }


        int cnt = 0;
        for(auto it : stonePos){
            if(ds.FindUparent(it.first) == it.first)cnt++;
        }

        return n - cnt;
    }   

};