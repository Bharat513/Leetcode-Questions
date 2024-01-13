class Solution {
    int calDiag(int l, int b){
        int temp = (l * l + b * b);
        return temp;
    }
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiag = 0, maxArea = 0;
        int n  = dimensions.size();
        for(int i = 0; i < n; i++){
            int diag = calDiag(dimensions[i][0], dimensions[i][1]);
            if(diag > maxDiag){
                maxDiag = diag;
                maxArea = dimensions[i][0] * dimensions[i][1];
            }else if(diag == maxDiag){
                maxArea = max(maxArea, dimensions[i][0] * dimensions[i][1]);
            }
        }
        return maxArea;
    }
};