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
    bool isEvenOddTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        int currLevel = 0;
        q.push({root, 0});
        int last = 0;
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();
            if(level > currLevel){
                currLevel = level;
                if(level % 2){
                    last = 1e9;

                }else last = 0;
            }
            if(level % 2){
                if((node->val)%2 == 1 || node->val >= last)return false;
                last = node->val;
            }else{
                if((node->val)%2 == 0 || node->val <= last)return false;
                last = node->val;
            }
            if(node->left)q.push({node->left, level+1});
            if(node->right)q.push({node->right, level+1});
        }
        return true;
    }
};