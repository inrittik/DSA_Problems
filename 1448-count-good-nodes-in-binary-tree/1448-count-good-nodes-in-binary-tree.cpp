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
    int ans = 0;
    void dfs(TreeNode* node, TreeNode* prev){
        if(node==NULL) return;
        if(prev==NULL){
            if(node->left) dfs(node->left, node);
            if(node->right) dfs(node->right, node);
            ans++;
        }
        else if(node->val>=prev->val){
            if(node->left) dfs(node->left, node);
            if(node->right) dfs(node->right, node);
            ans++;
        }
        else{
            if(node->left) dfs(node->left, prev);
            if(node->right) dfs(node->right, prev);
        }
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL) return 0;
        dfs(root, NULL);
        return ans;
    }
};