class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dist(n, vector<int> (m, 1e9));
        queue<pair<pair<int, int> , int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    dist[i][j] = 0;
                    q.push({{i, j}, 0});
                }
            }
        }

        int dr [] = {-1, 0, 1, 0};
        int dc [] = {0, 1, 0, -1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            q.pop();
            dist[r][c] = min(d, dist[r][c]);
            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && mat[nr][nc] != 0 && dist[nr][nc] > 1 + d)
                        q.push({{nr, nc}, d + 1});
            }
        }
        return dist;
    }
};