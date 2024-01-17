class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        int mod = 1e9 + 7;
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());
        
        unordered_map<int, bool> mp;
        for(int i = 0; i < hFences.size(); i++){
            int num1 = hFences[i];
            for(int j = i + 1; j < hFences.size(); j++){
                int len = hFences[j] - num1;
                mp[len] = true;
            }
        }
        long long ans = -1;
        
        for(int i = 0; i < vFences.size(); i++){
            long long  num1 = vFences[i];
            for(int j = i + 1; j < vFences.size(); j++){
                long long width = vFences[j] - num1;
                //long long area = (width * width)%mod;
                if(mp[width]) ans = max(ans, width);
            }
        }
        return ans == -1 ? ans : ((ans*ans) % mod);
        
        
    }
};