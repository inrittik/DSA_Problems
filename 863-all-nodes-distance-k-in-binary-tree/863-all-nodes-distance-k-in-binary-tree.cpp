/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<int, vector<int>> mp;
    void dfs(TreeNode* node){
        if(node==NULL) return;
        if(node->left){
            mp[node->val].push_back(node->left->val);
            mp[node->left->val].push_back(node->val);
            dfs(node->left);
        }
        if(node->right){
            mp[node->val].push_back(node->right->val);
            mp[node->right->val].push_back(node->val);
            dfs(node->right);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root);
        
        queue<int> q;
        q.push(target->val);
        unordered_map<int,int> vis;
        vis[target->val]++;
        int dist = 0;
        
        while(!q.empty()){
            int sz = q.size();
            dist++;
            vector<int> tmp;
            while(sz--){
                int node = q.front();
                q.pop();
                tmp.push_back(node);

                for(int it:mp[node]){
                    if(!vis[it]){
                        q.push(it);
                        vis[it]++;
                    }
                }
            }
            if(dist-1==k) return tmp;
        }
        vector<int> tmp;
        return tmp;
    }
};