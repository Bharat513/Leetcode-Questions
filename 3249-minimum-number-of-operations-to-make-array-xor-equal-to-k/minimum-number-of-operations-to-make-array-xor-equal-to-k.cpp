class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int Xor = nums[0];
        for(int i = 1; i < n; i++){
            Xor ^= nums[i];
        }
        Xor ^= k;
        int cnt = 0;
        while(Xor){
            cnt += (Xor & 1);
            Xor >>= 1;
        }
        return cnt;
    }
};