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
    int ans = 0;
    void dfs(TreeNode* node, vector<int>& val){
        if(node->left==NULL && node->right==NULL){
            val[node->val]++;
            int cnt = 0;
            for(int i=1; i<=9; ++i) if(val[i]%2!=0) cnt++;
            if(cnt<2) ans++;
            val[node->val]--;
            return;
        }
        val[node->val]++;
        if(node->left) dfs(node->left, val);
        if(node->right) dfs(node->right, val);
        val[node->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> val(10);
        dfs(root, val);
        return ans;
    }
};