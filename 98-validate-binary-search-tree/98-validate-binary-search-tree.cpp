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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        if(root==NULL) return inorder;
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
                inorder.push_back(root->val);
                root = root->right;
            }
        }
        return inorder;
    }
    bool isValidBST(TreeNode* root) {
        vector<int> v = inorderTraversal(root);
        int n = v.size();
        for(int i=1; i<n; ++i){
            if(v[i-1]>=v[i]) return false;
        }
        return true;
    }
};