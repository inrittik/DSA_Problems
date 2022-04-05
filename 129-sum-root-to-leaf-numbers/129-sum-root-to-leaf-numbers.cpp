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
    int getSum(TreeNode* root, int level, int sum){
        if(root->left==NULL && root->right==NULL) return sum*10+root->val;
        
        sum*=10;
        sum+=root->val;
        
        if(root->right==NULL) return getSum(root->left, level+1, sum);
        if(root->left==NULL) return getSum(root->right, level+1, sum);
        
        return getSum(root->left, level+1, sum)+getSum(root->right, level+1, sum);
    }
    int sumNumbers(TreeNode* root) {
        if(root==NULL) return 0;
        return getSum(root, 0, 0);
    }
};