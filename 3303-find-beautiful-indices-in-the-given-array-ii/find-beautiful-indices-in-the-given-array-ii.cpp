class Solution {
    vector<int> lps(string m){
        int n = m.size();
        vector<int> lps(n, 0);
        for(int i = 1; i < n; i++){
            int prefIdx = lps[i - 1];
            while(prefIdx > 0 && m[prefIdx] != m[i]){
                prefIdx = lps[prefIdx - 1];
            }
            lps[i] = prefIdx + (m[prefIdx] == m[i]);
        }
        return lps;
    }
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int n = s.size();
        int n1 = a.size();
        int n2 = b.size();
        string aStr = a + "#" + s;
        string bStr = b + "#" + s;
        vector<int> aLps = lps(aStr);
        vector<int> bLps = lps(bStr);
        vector<int> aVec, bVec;
        for(int i = n1; i < aLps.size(); i++){
            if(aLps[i] == n1){
                aVec.push_back(i - 2 * n1);
            }
        }
        for(int i = n2; i < bLps.size(); i++){
            if(bLps[i] == n2){
                bVec.push_back(i - 2 * n2);
            }
        }
        vector<int> ans;
        for(int i = 0;  i < aVec.size(); i++){
            // for(int j = 0; j < bVec.size(); j++){
            //     if(abs(aVec[i] - bVec[j]) <= k){
            //         ans.push_back(aVec[i]);
            //         break;
            //     }
            // }
            int bLower = lower_bound(bVec.begin(), bVec.end(), aVec[i]) - bVec.begin();
         
            if(bLower != bVec.size() && abs(bVec[bLower] - aVec[i]) <= k)ans.push_back(aVec[i]);
            else if(bLower != 0 && abs(bVec[bLower - 1] - aVec[i]) <= k)ans.push_back(aVec[i]);
            
        }
        return ans;
    }
};