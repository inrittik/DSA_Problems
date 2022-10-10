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
class FindElements {
public:
    unordered_map<int, int> mp;
    void recover(TreeNode* node, int  val){
        node->val = val;
        if(node->left) {
            mp[2*val+1]++;
            recover(node->left,2*val+1);
        }
        if(node->right) {
            mp[2*val+2]++;
            recover(node->right,2*val+2);
        }
    }
    FindElements(TreeNode* root) {
        mp[0]++;
        if(root->left) recover(root, 0);
        if(root->right) recover(root, 0);
    }
    
    bool find(int target) {
        return mp.find(target)!=mp.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */