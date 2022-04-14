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
    bool isValidBST(TreeNode* root) {
        long curr, prev;
        prev = LONG_MIN;
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
                curr = root->val;
                if(curr<=prev) return false;
                prev = curr;
                root = root->right;
            }
        }
        return true;
    }
};