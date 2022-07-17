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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0}); // node and index
        int mxWidth = 0;
        while(!q.empty()){
            int n = q.size();
            unsigned long long left = q.front().second, right = 0;
            while(n-->0){
                auto node = q.front();
                q.pop();
                right = node.second;
                
                if(node.first->left){
                    q.push({node.first->left, 2*right+1});
                }
                if(node.first->right){
                    q.push({node.first->right, 2*right+2});
                }
            }
            
            mxWidth = max(mxWidth, (int)(right - left +  1));
        }
        return mxWidth;
    }
};