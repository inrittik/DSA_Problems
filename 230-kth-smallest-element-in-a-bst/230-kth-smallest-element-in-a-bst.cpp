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
    int kthSmallest(TreeNode* root, int k) {
        vector<TreeNode*> tree;
        stack<TreeNode*> s;
        while(true){
            if(root){
                s.push(root);
                root = root->left;
            }
            else{
                if(s.empty()) break;
                root = s.top();
                s.pop();
                tree.push_back(root);
                root = root->right;
            }
        }
        return tree[k-1]->val;
    }
};