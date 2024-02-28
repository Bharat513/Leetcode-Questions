/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return -1;
        queue<pair<TreeNode*,int>> q;
        
        q.push({root,0});
        //vector<int> ans;
        vector<int> temp;
        while(!q.empty()){
            TreeNode* node=q.front().first;
            int level=q.front().second;
            q.pop();
            
             
            if(level>ans.size()){
                ans.push_back(temp);
                temp.clear();
            }
            temp.push_back(node->val);
           
            
            if(node->left) q.push({node->left,level+1});
            if(node->right) q.push({node->right,level+1});
        }
        if(!temp.empty()){
            ans.push_back(temp);
        }
        return temp[0];
    }
};