class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        if(y > x) return y - x;

        queue<int> q;
        int cnt = 0;
        vector<bool> vis(1e5, 0);
        q.push(x);
        vis[x] = 1;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                int num = q.front();
                q.pop();
                if(num == y) return cnt;
                
                if(num + 1 < 1e9+11 && vis[num + 1] == 0){
                    q.push(num + 1);
                    vis[num + 1] = 1;
                }
                if(num - 1 > 0 && vis[num - 1] == 0){
                    q.push(num - 1);
                    vis[num - 1] = 1;
                }
                if(num % 11 == 0 && vis[num / 11] == 0 && (num / 11) > 0){
                    q.push(num/11);
                    vis[num / 11] = 1;
                }
                if(num % 5 == 0 && vis[num / 5] == 0 && (num / 5) > 0){
                    q.push(num/5);
                    vis[num / 5] = 1;
                }

            }
            cnt++;
        }
        return cnt;
    }
};