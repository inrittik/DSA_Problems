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
    TreeNode* build(vector<int>& postorder, int poStart, int poEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int>& mp){
        if(poStart>poEnd || inStart>inEnd) return NULL;
        
        TreeNode* node = new TreeNode(postorder[poEnd]);
        int ind = mp[node->val];
        int numsRight = inEnd - ind;
        
        node->right = build(postorder, poEnd-numsRight, poEnd-1, inorder, ind+1, inEnd, mp);
        node->left = build(postorder, poStart, poEnd-numsRight-1, inorder, inStart, ind-1, mp);
        
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> mp;
        for(int i=0; i<inorder.size(); ++i){
            mp[inorder[i]] = i;
        }
        TreeNode* root = build(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, mp);
        return root;
    }
};