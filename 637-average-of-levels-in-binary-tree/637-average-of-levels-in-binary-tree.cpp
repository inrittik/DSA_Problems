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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            double sum = 0, sz, tmp;
            tmp = sz = q.size();
            while(sz--){
                TreeNode* f = q.front();
                q.pop();
                sum += f->val;
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
            ans.push_back(sum/tmp);
        }
        return ans;
    }
};