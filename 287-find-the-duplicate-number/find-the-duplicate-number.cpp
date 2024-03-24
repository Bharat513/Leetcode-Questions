class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = nums[0];
        int high = nums[0];
        do{
            low = nums[low];
            high = nums[nums[high]];
        }while(low != high);

        high = nums[0];
        while(high != low){
            low= nums[low];
            high = nums[high];
        }
        return low;
    }
};