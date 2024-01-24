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
    void helper(TreeNode* node, int &cnt,  vector<int> cntVec){
        if(node->left == NULL && node->right == NULL){
            int n = 0;
            cntVec[node->val - 1]++;
            int oddCnt = 0;
            for(int i = 0; i < 9; i++){
                if(cntVec[i] % 2)oddCnt++;
                n += cntVec[i];
            }
            if(n % 2 && oddCnt == 1)cnt++;
            if(n % 2 == 0 && oddCnt == 0)cnt++;
            return;
        }

        cntVec[node->val - 1]++;
        if(node->left) helper(node->left, cnt, cntVec);
        if(node->right) helper(node->right, cnt, cntVec);
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        int cnt = 0;
        vector<int> cntVec(9, 0);

        helper(root, cnt, cntVec);
        return cnt;
    }
};