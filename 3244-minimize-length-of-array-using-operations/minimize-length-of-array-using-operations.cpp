class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int el = nums[0], cnt = 0;
        int minEle = el;
        for(int i = 0; i < n; i++){
            if(nums[i] % el){
                minEle = min(minEle, nums[i] % el);
            }
            if(nums[i] == el)cnt++;
        }
        if(el != minEle)return 1;
        else return (cnt + 1)/2;
    }
};