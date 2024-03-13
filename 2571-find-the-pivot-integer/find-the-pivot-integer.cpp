class Solution {
public:
    int pivotInteger(int n) {
        int sum = n * (n + 1)/2;
        for(int i = 1; i <= n; i++){
            int leftSum = (i * (i + 1))/2;
            int RightSum = sum + i - leftSum;
            if(RightSum == leftSum)return i;
        }
        return -1;
    }
};