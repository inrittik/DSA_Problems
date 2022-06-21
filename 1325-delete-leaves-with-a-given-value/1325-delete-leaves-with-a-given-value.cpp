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
    bool helper(TreeNode* root, int target){
        if(!root->left && !root->right) {
            if(root->val==target) return true;;
            return false;
        }
        
        if(root->left) {
            if(helper(root->left, target)) root->left=NULL;
        }
        if(root->right) {
            if(helper(root->right, target)) root->right=NULL;
        }
        
        if(!root->left && !root->right){
            if(root->val==target){
                return true;
            }
        }
        return false;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        helper(root, target);
        if(!root->left && !root->right){
            if(root->val==target) return NULL;
        }
        return root;
    }
};