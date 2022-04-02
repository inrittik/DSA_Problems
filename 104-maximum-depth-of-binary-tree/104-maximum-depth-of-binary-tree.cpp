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
    int findDepth(TreeNode* root, int depth){
        if(!root) return depth;
        
        return max(findDepth(root->left, depth+1), findDepth(root->right, depth+1));
    }
    int maxDepth(TreeNode* root) {
        int ans = findDepth(root, 0);
        return ans;
    }
};