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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        
        TreeNode* node = root;
        TreeNode* prev = NULL;
        if(root->val==key){
            if(root->left && root->right){
                prev = root->left;
                root = root->right;
                node = root;
                TreeNode* itr = root;
                while(itr){
                    node = itr;
                    itr = itr->left;
                }
                node->left = prev;
                
                return root;
            }
            else if(root->left==NULL){
                root = root->right;
                
                return root;
            }
            else if(root->right==NULL){
                root = root->left;
                
                return root;
            }
            else return NULL;
        }
        while(node){
            if(node->val>key){
                prev = node;
                node = node->left;
            }
            else if(node->val<key){
                prev = node;
                node = node->right;
            }
            else{
                if(node->left && node->right){
                    TreeNode* itr = NULL;
                    if(node->val>prev->val){
                        prev->right = node->right;
                        itr = prev->right;
                        while(itr){
                            prev = itr;
                            itr = itr->left;
                        }
                        prev->left = node->left;
                    }
                    else{
                        prev->left = node->right;
                        itr = prev->left;
                        while(itr){
                            prev = itr;
                            itr = itr->left;
                        }
                        prev->left = node->left;
                    }
                }
                else if(node->left==NULL){
                    if(node->val>prev->val){
                        prev->right = node->right;
                    }
                    else{
                        prev->left = node->right;
                    }
                }
                else if(node->right==NULL){
                    if(node->val>prev->val){
                        prev->right = node->left;
                    }
                    else{
                        prev->left = node->left;
                    }
                }
                else{
                    if(node->val>prev->val){
                        prev->right = NULL;
                    }
                    else{
                        prev->left = NULL;
                    }
                }
                break;
            }
        }
        
        return root;
    }
};