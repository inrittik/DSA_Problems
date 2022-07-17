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
    int num = 0;
    void helper(TreeNode* node){
        if(node==NULL) return;
        
        helper(node->right);
        num += node->val;
        node->val = num;
        helper(node->left);
    }
    TreeNode* bstToGst(TreeNode* root) {
        helper(root);
        return root;
    }
};