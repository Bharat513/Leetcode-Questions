class Solution {
public:
    int maximumLength(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        unordered_map<long long, long long> cntMap;
        
        for(auto it : nums){
            cntMap[it]++;
        }
        int maxi = 0;
        if(cntMap.size() == 1 && nums[0] == 1){
            if(cntMap[1] % 2)cntMap[1];
            else cntMap[1] - 1;
        }
        if(cntMap.size() <= 1) return 1;
        for(int i = 0; i < n; i++){
            long long temp = nums[i];
            int cnt = 0;
            
            while(cntMap[temp] > 1){
                if(temp == 1){
                    if(cntMap[1] % 2)cnt = cntMap[1];
                    else cnt = cntMap[1] - 1;
                    maxi = max(cnt, maxi);
                    break;
                }
                cnt += 2;
                if(temp > 1e5)break;
                temp *= temp;
            }
            if(cntMap[temp] == 0){
                cnt--;
                maxi = max(cnt, maxi);
            }
            if(cntMap[temp] >= 1){
                if(cntMap[temp] == 1)cnt++;
                else cnt--;
                
                maxi = max(cnt, maxi);
            }
        }
        return maxi;
    }
};