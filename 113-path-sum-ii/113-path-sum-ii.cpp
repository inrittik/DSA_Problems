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
    void getPath(TreeNode* root, int target, vector<int> osf, vector<vector<int>> &ans){
        if(root==NULL) return;
        
        osf.push_back(root->val);
        if(root->val==target && root->left==NULL && root->right==NULL){
            ans.push_back(osf);
            return;
        }
        getPath(root->left, target-root->val, osf, ans);
        getPath(root->right, target-root->val, osf, ans);
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>> ans;
        vector<int> osf;
        
        getPath(root, target, osf, ans);
        return ans;
    }
};