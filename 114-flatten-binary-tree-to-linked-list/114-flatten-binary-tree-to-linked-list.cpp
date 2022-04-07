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
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        TreeNode* node;
        TreeNode* itr;
        if(root->right) node = root->right;
        root->right = root->left;
        root->left = NULL;
        itr = root;
        while(itr->right){
            itr = itr->right;
        }
        itr->right = node;
        flatten(root->right);
    }
};