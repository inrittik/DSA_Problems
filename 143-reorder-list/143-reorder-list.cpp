/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slo = head;
        ListNode* fas = head;
        stack<ListNode*> st;
        while(fas && fas->next){
            slo = slo->next;
            fas = fas->next->next;
        }
        ListNode* mid = slo;
        while(slo){
            st.push(slo);
            slo = slo->next;
        }
        
        ListNode* ptr = head;
        while(!st.empty()){
            ListNode* node = st.top();
            st.pop();
            if(ptr==node) break;
            node->next = ptr->next;
            ptr->next = node;
            ptr = ptr->next->next;
        }
        ptr->next = NULL;
    }
};