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
    void getTree(TreeNode* root, int l, vector<vector<int>> &ans){
        if(root==NULL) return;
        if(ans.size()==l) ans.push_back(vector<int>());
        ans[l].push_back({root->val});
        
        getTree(root->left, l+1, ans);
        getTree(root->right, l+1, ans);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        vector<vector<int>> res;
        int level = 0;
        if(root==NULL) return res;
        ans.push_back({root->val});
        
        getTree(root->left, level+1, ans);
        getTree(root->right, level+1, ans);
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};