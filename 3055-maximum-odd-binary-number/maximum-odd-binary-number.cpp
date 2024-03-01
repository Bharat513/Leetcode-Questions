class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size();
        int onesCount = 0;
        for(auto it : s){
            if(it == '1') onesCount++;
        }
        string newS = "";
        while(onesCount > 1){
            newS += '1';
            onesCount--;
        }
        while(newS.size() < s.size()){
            if(newS.size() + 1 == s.size() && onesCount >= 1){
                newS += '1';
            }else{
                newS += '0';
            }
        }
        return newS;
            
    }
};