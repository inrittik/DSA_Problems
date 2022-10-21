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
    unordered_map<string, int> mp;
    vector<TreeNode*> v;
    string dfs(TreeNode* root){
        string l = "", r = "";
        if(root->left) l=dfs(root->left);
        if(root->right) r=dfs(root->right);
        string s = to_string(root->val)+'.'+l+'.'+r;
        if(++mp[s]==2) v.push_back(root);
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return v;
    }
};