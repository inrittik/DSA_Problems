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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        ans.push_back({root->val});
        
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();
            if(node->left){
                q.push({node->left, level+1});
                if(level<=ans.size()-1) {
                    ans[level].push_back(node->left->val);
                }
                else{
                    ans.push_back(vector<int>(1, node->left->val));
                }
            }
            if(node->right){
                q.push({node->right, level+1});
                if(level<=ans.size()-1) {
                    ans[level].push_back(node->right->val);
                }
                else{
                    ans.push_back(vector<int>(1, node->right->val));
                }
            }
        }
        return ans;
    }
};