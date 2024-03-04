class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        int maxi = 0;
        sort(tokens.begin(), tokens.end());
        int low = 0, high = n - 1;
        int score = 0;
        while(low <= high){
            if(tokens[low] <= power){
                score += 1;
                power  -= tokens[low];
                maxi = max(maxi, score);
                low++;
            }else if(score > 0){
                score -= 1;
                power  += tokens[high];
                high--;
            }else break;
        }
        return maxi;

    }
};