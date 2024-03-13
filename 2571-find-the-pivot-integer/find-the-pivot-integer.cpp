class Solution {
public:
    int pivotInteger(int n) {
        int sum = n * (n + 1)/2;
        int sqrRoot = sqrt(n * (n + 1)/2);
        
        return sqrRoot * sqrRoot == sum ? sqrRoot : -1;
    }
};