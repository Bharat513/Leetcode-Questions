class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses, 0);
        for(int i = 0; i < prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0)q.push(i);
        }
        int cnt = 0;
        while(!q.empty()){
            int course = q.front();
            q.pop();
            cnt++;
            for(auto it : adj[course]){
                indegree[it]--;
                if(indegree[it] == 0)q.push(it);
            }
        }
        return cnt == numCourses;
    }
};