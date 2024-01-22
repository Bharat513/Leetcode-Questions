class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         vector<int> adj[numCourses];
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        queue<int> q;
	    vector<int> topo;
	    vector<int> indegree(numCourses,0);
	    for(int i=0;i<numCourses;i++){
	        for(auto it:adj[i]){
	            indegree[it]++;
	        }
	    }
	    
	    for(int i=0;i<numCourses;i++){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
	    while(!q.empty()){
	        int Node=q.front();
	        q.pop();
	        topo.push_back(Node);
	        for(auto it:adj[Node]){
	            indegree[it]--;
	            if(indegree[it]==0){
	                q.push(it);
	            }
	        }
	    }
	    if(topo.size()==numCourses) return topo;
        else return {};
    }
};