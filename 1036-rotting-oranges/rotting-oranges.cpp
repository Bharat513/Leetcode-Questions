class Solution {

    
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> pq;
        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(grid[row][col] == 2){
                    pq.push({row, col});
                    vis[row][col] = 1;
                }
            }
        }

        //bfs
        int cost = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        while(!pq.empty()){
            bool flag = false;
            int size = pq.size();
            for(int i = 0; i < size; i++){
                int r = pq.front().first;
                int c = pq.front().second;
                pq.pop();
                for(int j = 0; j < 4; j++){
                            int nr = r + drow[j];
                            int nc = c + dcol[j];
                            if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == 1){
                                pq.push({nr, nc});
                                vis[nr][nc] = 1;
                                flag = true;
                            }
                        
                    
                } 
                
            }
            if(flag)cost++;
        }

        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(!vis[row][col] && grid[row][col] == 1){
                    return -1;
                }
            }
        }
        return cost;


    }
};