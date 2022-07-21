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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || left==right) return head;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* curr = dummy;
        for(int i=0; i<left-1; i++){
            curr = curr->next;
        }
        ListNode* next = curr->next;
        
        for(int i=0; i<(right-left); i++){
            ListNode* tmp = curr->next;
            curr->next = next->next;
            next->next = next->next->next;
            curr->next->next = tmp;
        }
        
        return dummy->next;
    }
};