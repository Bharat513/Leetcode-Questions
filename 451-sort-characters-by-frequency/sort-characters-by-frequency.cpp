class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int,char>> ans('z'+1,{0,0});

        for(char c:s){
            ans[c]={ans[c].first+1,c};
        }
        sort(ans.begin(),ans.end());
        string output="";
        for(auto it:ans){

            output=string(it.first,it.second)+output;
            //cout<<string(it.first,it.second)<<" ";
            //cout<<string(4, 'a')<<" ";
        }

        return output;


    }
};