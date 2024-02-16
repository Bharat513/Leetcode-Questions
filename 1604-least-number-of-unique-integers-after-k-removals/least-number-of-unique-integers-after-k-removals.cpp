class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for(auto it : arr)mp[it]++;

        vector<int> freq;
        for(auto it : mp){
            freq.push_back(it.second);
        }
        sort(freq.begin(), freq.end());

        int i = 0;
        int n = freq.size();
        while(k >= 0){
            if(i >= n)return 0;
            if(freq[i] <= k){
                k -= freq[i];
                i++;
            } 
            else return n - i;
        }
        return n - i;
    }
};