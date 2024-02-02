class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string num = "123456789";
        vector<int> ans;
        for(int i = 0; i < 9; i++){
            for(int j = i; j < 9; j++){
                string subStr = num.substr(i, j - i + 1);
                int digit = stoi(subStr);
                if(digit >= low && digit <= high)ans.push_back(digit);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};