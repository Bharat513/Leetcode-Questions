class Solution {
    
public:

    int evalRPN(vector<string>& tokens) {
        
        stack<int> st;

        for(auto it : tokens){
            if(it == "+"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int res = b + a;
                st.push(res);
            }else if(it == "-"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int res = b - a;
                st.push(res);
            }else if(it == "*"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int res = b * a;
                st.push(res);
            }else if(it == "/"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int res = b / a;
                st.push(res);
            }else{
                int num  = stoi(it);
                st.push(num);
            }
        }
        return st.top();
    }
};