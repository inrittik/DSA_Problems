/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* dummy = new Node(0);
        Node* curr = dummy;
        Node* itr = head;
        unordered_map<Node*, Node*> mp;
        while(itr){
            Node* node = new Node(itr->val);
            curr->next = node;
            mp[itr] = node;
            curr = curr->next;
            itr = itr->next;
        }
        itr = head;

        while(itr){
            mp[itr]->random = mp[itr->random];
            itr = itr->next;
        }
        return dummy->next;
    }
};