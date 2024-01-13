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

    void buildGraph(TreeNode* root, vector<vector<int>> &adj){
        if(root == NULL) return;
        if(root->left){
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
        }

        if(root->right){
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
        }
        buildGraph(root->left, adj);
        buildGraph(root->right, adj);
    }

    int bfs(int start, vector<vector<int>> &adj, vector<bool> &vis){
        queue<int> q;
        q.push(start);
        vis[start] = 1;
        int len = 0;
        while(! q.empty()){
            int size = q.size();
            while(size > 0){
                int node = q.front();
                q.pop();
                for(int i = 0; i < adj[node].size(); i++){
                    if(vis[adj[node][i]] != 1){
                        q.push(adj[node][i]);
                        vis[adj[node][i]] = 1;
                    }
                }
                size--;
            }
            len++;
        }
        return len - 1;
    }
    
public:
    int amountOfTime(TreeNode* root, int start) {
        vector<vector<int>> adj (100001);
        vector<bool> vis(100001, 0);
        buildGraph(root, adj); 
        return bfs(start, adj, vis);
    }
};