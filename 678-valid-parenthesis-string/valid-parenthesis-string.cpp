class Solution {

    bool check(string s){
        int star = 0;
        int openPara = 0;
        for(auto it : s){
            if(it == '(')openPara++;
            else if(it == '*')star++;
            else{
                if(openPara == 0 && star == 0)return false;
                else if(openPara) openPara--;
                else star--;
            }
        }
        if(openPara == 0 || openPara <= star)return true;
        return false;
    }
public:
    bool checkValidString(string s) {
        int n = s.size();
      stack<int> star;
      stack<int> openPara;
        for(int i = 0; i < n; i++){
            if(s[i] == '(')openPara.push(i);
            else if(s[i] == '*')star.push(i);
            else{
                if(openPara.size() == 0 && star.size() == 0)return false;
                else if(openPara.size()) openPara.pop();
                else star.pop();
            }
        }
        while(!openPara.empty()){
            int top = openPara.top();
            if(star.size() == 0) return false;
            openPara.pop();
            if(top > star.top())return false;
            star.pop();
        }
        return true;
    }
};