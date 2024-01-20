class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        if(n==0) return 0;

        vector<int> prevGreater(n);
        vector<int> nextGreater(n);
        stack<pair<int,int>> s1,s2;

        for(int i=0;i<n;i++){
            int count=1;
            while(!s1.empty() && arr[s1.top().first]>arr[i]){
                count+=s1.top().second;
                s1.pop();
            }
            s1.push({i,count});
            prevGreater[i]=count;
        }

        for(int i=n-1;i>=0;i--){
            int count=1;
            while(!s2.empty() && arr[s2.top().first]>=arr[i]){
                count+=s2.top().second;
                s2.pop();
            }
            s2.push({i,count});
            nextGreater[i]=count;
        }

        long long ans=0;
        int mod=int(pow(10,9)+7);
        for(int i=0;i<n;i++){
            ans += ((static_cast<long long>(arr[i]) * prevGreater[i]) % mod) * nextGreater[i];
            ans%=mod;
        }
        int output=int(ans%mod);
        return output;



    }
};