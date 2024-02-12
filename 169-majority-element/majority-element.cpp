class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majEmt=nums[0];
        int cnt=1;
        for(int i=1;i<nums.size();i++){
            if(cnt==0){
                majEmt=nums[i];
                cnt++;
            }else{
                if(nums[i]==majEmt) cnt++;
                else{
                    cnt--;
                }
            }
        }
        return majEmt;
    }
};