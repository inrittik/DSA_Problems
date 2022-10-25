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
    pair<TreeNode*,int> helper(TreeNode* node, int d){
        if(!node) return {NULL, 0};
        auto l = helper(node->left, d+1);
        auto r = helper(node->right, d+1);
        if(l.second==r.second){
            if(l.second==0) l.second=d;
            return {node, l.second};
        }
        if(l.second>r.second) return l;
        else return r;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        auto ans = helper(root, 0);
        return ans.first;
    }
};