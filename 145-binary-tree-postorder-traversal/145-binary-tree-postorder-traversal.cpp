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
    void Postorder(TreeNode* root, vector<int> &tree){
        if(!root) return;
        
        Postorder(root->left, tree);
        Postorder(root->right, tree);
        tree.push_back(root->val);
        
        return;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> tree;
        
        Postorder(root, tree);
        
        return tree;
    }
};