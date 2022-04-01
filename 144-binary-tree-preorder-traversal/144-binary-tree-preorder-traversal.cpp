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
    void Preorder(TreeNode* root, vector<int> &tree){
        if(root==NULL) return;
        
        tree.push_back(root->val);
        Preorder(root->left, tree);
        Preorder(root->right, tree);
        return;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> tree;
        
        Preorder(root, tree);
        return tree;
    }
};