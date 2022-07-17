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
    map<int, int> mp;
    TreeNode* helper(vector<int>& preorder, vector<int>& postorder, int start, int end, int &preInd){
        if(preInd>=preorder.size() || start>end) return NULL;
        TreeNode* node = new TreeNode(preorder[preInd]);
        preInd++;
        
        if(start==end) return node;
        int idx;
        for (idx = start; idx <= end; ++idx)
            if (preorder[preInd] == postorder[idx]) break;
        
        if(idx<=end){
            node->left = helper(preorder, postorder, start, idx, preInd);
            node->right = helper(preorder, postorder, idx+1, end-1, preInd);
        }
        
        return node;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int preInd = 0;
        return helper(preorder, postorder, 0, preorder.size()-1, preInd);
    }
};