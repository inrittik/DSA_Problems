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
    TreeNode* build(vector<int>& preorder, int prStart, int prEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int>& mp){
        if(prStart>prEnd || inStart>inEnd) return NULL;
        TreeNode* node = new TreeNode(preorder[prStart]);
        int ind = mp[node->val];
        int numsLeft = ind-inStart;
        
        node->left = build(preorder, prStart+1, prStart+numsLeft, inorder, inStart, ind-1, mp);
        node->right = build(preorder, prStart+numsLeft+1, prEnd, inorder, ind+1, inEnd, mp);
        
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mp;
        for(int i=0; i<inorder.size(); ++i){
            mp[inorder[i]] = i;
        }
        TreeNode* root = build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, mp);
        return root;
    }
};