// Populating Next right pointers in each node

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL){
            return root;
        }
        // if(root->left && root->right)
        if(root->left==NULL){
            return root;
        }
        root->left->next=root->right;
        if(root->next){
            root->right->next=root->next->left;   
        }
        connect(root->left);
        connect(root->right);
        return root;
    }
};