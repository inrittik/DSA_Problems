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
    unordered_map<TreeNode*, int> mp;
    int rob(TreeNode* root) {
        if(mp[root]) return mp[root];
        if(root==NULL) return 0;
         
        int pick=root->val;
        if(root->left) pick+=(rob(root->left->left)+rob(root->left->right));
        if(root->right) pick+=(rob(root->right->left)+rob(root->right->right));
        
        int notPick=(rob(root->left)+rob(root->right));
        
        return mp[root]=max(pick,notPick);
    }
};