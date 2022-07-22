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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        
        ListNode* curr = dummy;
        ListNode* prev = dummy;
        ListNode* next = NULL;
        ListNode* tmp =next;
        int i=0;
        while(curr=curr->next) i++;
        
        while(i>=k){
            curr = prev->next;
            next = curr->next;
            
            for(int j=1;j<k; ++j){
                tmp= next->next;
                next->next = prev->next;
                prev->next = next;
                curr->next = tmp;
                next = tmp;
            }
            prev = curr;
            i-=k;
        }
        return dummy->next;
    }
};