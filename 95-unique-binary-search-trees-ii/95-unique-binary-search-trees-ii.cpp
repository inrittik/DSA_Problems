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
    vector<TreeNode*> helper(int start, int end){
        if(start>end) return {NULL};
        
        vector<TreeNode*> left, right, ans;
        for(int i=start; i<=end; ++i){
            left = helper(start, i-1);
            right = helper(i+1, end);
            
            for(auto l:left){
                for(auto r:right){
                    TreeNode* node = new TreeNode(i);
                    node->left = l;
                    node->right = r;
                    ans.push_back(node);
                }
            }
        }
        
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return helper(1, n);
    }
};