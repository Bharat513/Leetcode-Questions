class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<pair<int, int>> adj[n];
        for(auto it : meetings){
            int p1 = it[0];
            int p2 = it[1];
            int time = it[2];
            adj[p1].push_back({p2, time});
            adj[p2].push_back({p1, time});
        }

        vector<int> vis(n, 0);
        
        vector<int> ans;
        
        priority_queue<pair<int,int> , vector<pair<int,int> > , greater<pair<int,int>> > pq;
        pq.push({0, 0});
        
        pq.push({0, firstPerson});
       
       

        

        while(!pq.empty()){
            int node  = pq.top().second;
            int time = pq.top().first;
            pq.pop();
            if(vis[node])continue;
            vis[node] = 1;
            ans.push_back(node);
            for(auto it : adj[node]){
                int adjNode = it.first;
                int cost = it.second;
                if( !vis[adjNode] && time  <= cost){
                    
                    
                    pq.push({cost, adjNode});
                }
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;

    }
};