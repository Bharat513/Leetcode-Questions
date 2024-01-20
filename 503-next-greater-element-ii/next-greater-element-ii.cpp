class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        stack<int> st;
        vector<int> ans(n,-1);
        
        //st.push(INT_MAX);
        for(int i=2*n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums[i%n]){
                st.pop();
            }
            if(i<n && !st.empty()){
                //if(st.top()==INT_MAX) ans.push_back(-1);
                ans[i]=st.top();
            }

            st.push(nums[i%n]); 
        }
        
        return ans;

        
    }
};