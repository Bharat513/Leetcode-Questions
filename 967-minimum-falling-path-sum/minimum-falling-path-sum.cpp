class Solution {
private:
    int helper(int row,int col,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        int n=matrix.size();
        if(row<0 || col<0 ||col>n-1) return 1e9;
        if(row==0) return matrix[row][col];
        if(dp[row][col]!=-1) return dp[row][col]; 
        int up=matrix[row][col]+helper(row-1,col,matrix,dp);
        int leftup=matrix[row][col]+helper(row-1,col-1,matrix,dp);
        int rightup=matrix[row][col]+helper(row-1,col+1,matrix,dp);
        return dp[row][col]=min(up,min(leftup,rightup));
    }    
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        
        vector<int> prev(n,1e9);
        for(int i=0;i<n;i++){
            prev[i]=matrix[0][i];
        }
        for(int row=1;row<n;row++){
            vector<int> curr(n,1e9);
            for(int col=0;col<n;col++){
                int down=1e9;
                int leftdown=1e9;
                int rightdown=1e9;
                down=matrix[row][col]+prev[col];
                if(col>0) leftdown=matrix[row][col]+prev[col-1];
                if(col<n-1) rightdown=matrix[row][col]+prev[col+1];
               curr[col]=min(down,min(leftdown,rightdown));
            }
            prev=curr;
            
        }
        int minSum=1e9;
        for(int i=0;i<n;i++){
            minSum=min(minSum,prev[i]);
        }
        return minSum;
        
    }
};