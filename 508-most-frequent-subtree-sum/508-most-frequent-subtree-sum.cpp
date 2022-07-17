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
    unordered_map<int, int> mp;
    int helper(TreeNode* node){
        if(node==NULL) return 0;
        int left = helper(node->left);
        int right = helper(node->right);
        
        mp[left+node->val+right]++;
        return left+node->val+right;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        helper(root);
        int mx;
        for(auto m:mp){
            mx = max(mx, m.second);
        }
        vector<int> ans;
        for(auto m:mp){
            if(m.second==mx) ans.push_back(m.first);
        }
        return ans;
    }
};