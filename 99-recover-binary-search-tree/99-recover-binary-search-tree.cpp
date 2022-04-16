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
    void recoverTree(TreeNode* root) {
        priority_queue<int, vector<int>, greater<int>> pq;
        stack<TreeNode*> s;
        TreeNode* node = root;
        while(true){
            if(node){
                s.push(node);
                node = node->left;
            }
            else{
                if(s.empty()) break;
                node = s.top();
                s.pop();
                pq.push(node->val);
                node = node->right;
            }
        }
        node = root;
        while(true){
            if(node){
                s.push(node);
                node = node->left;
            }
            else{
                if(s.empty()) break;
                node = s.top();
                s.pop();
                int x = pq.top();
                pq.pop();
                node->val = x;
                node = node->right;
            }
        }
    }
};