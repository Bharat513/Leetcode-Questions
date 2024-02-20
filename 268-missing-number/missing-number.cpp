class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=n*(n+1)/2;
        int countSum=0;
        for(int i=0;i<n;i++){
            countSum +=nums[i];
        }
        int ans=sum-countSum;
        return ans;
    }
};