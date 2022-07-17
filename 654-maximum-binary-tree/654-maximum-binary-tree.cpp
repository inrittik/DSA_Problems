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
    TreeNode* helper(vector<int>& nums, int start, int end){
        if(start>end) return NULL;
        
        int idx = start;
        int mx = nums[start];
        for(int i=start; i<=end; ++i){
            if(nums[i]>mx){
                mx = nums[i];
                idx = i;
            }
        }
        
        TreeNode* node = new TreeNode(nums[idx]);
        if(start==end) return node;
        
        node->left = helper(nums, start, idx-1);
        node->right = helper(nums, idx+1, end);
        return node;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        return helper(nums, 0, n-1);
    }
};