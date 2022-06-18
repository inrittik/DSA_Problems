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
    int solve(TreeNode* root, int num){
        if(root==NULL || root->val!=num) return 0;
        
        return 1+max(solve(root->left,num),solve(root->right,num));
    }
    int longestUnivaluePath(TreeNode* root) {
        if(root==NULL) return 0;
        int l=solve(root->left, root->val);
        int r=solve(root->right, root->val);
        return max(l+r, max(longestUnivaluePath(root->left), longestUnivaluePath(root->right)));
    }
};