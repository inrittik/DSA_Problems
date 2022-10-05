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
    void attachRow(TreeNode* root, int val, int depth, int level){
        if(root==NULL) {
            root = new TreeNode(val);
            return;   
        }
        if(level==depth-1){
            TreeNode* left = root->left;
            TreeNode* right = root->right;
            root->left = new TreeNode(val);
            root->right = new TreeNode(val);
            
            root->left->left = left;
            root->right->right = right;
        }
        
        attachRow(root->left, val, depth, level+1);
        attachRow(root->right, val, depth, level+1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(root==NULL) return new TreeNode(val);
        if(depth==1){
            TreeNode* node = new TreeNode(val);
            node->left = root;
            root = node;
        }
        attachRow(root, val, depth, 1);
        
        return root;
    }
};