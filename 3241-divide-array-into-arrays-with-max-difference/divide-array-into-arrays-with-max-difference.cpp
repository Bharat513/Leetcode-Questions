class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0;
        while(i < n){
            vector<int> temp;
            int j = 0;
            int first = nums[i];
            while(j < 3){
                int diff = nums[i] - first;
                
                if(diff > k) {
                    
                    vector<vector<int>> empty;
                    return empty;
                }
                else{
                    cout<<diff<<" ";
                    temp.push_back(nums[i]);
                }
                j++;
                i++;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};