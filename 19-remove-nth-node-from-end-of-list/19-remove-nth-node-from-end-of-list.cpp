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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || head->next==NULL) return NULL;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* slo = dummy, *fas = dummy;
        while(n){
            fas = fas->next;
            n--;
        }
        while(fas->next){
            slo = slo->next;
            fas = fas->next;
        }
        slo->next = slo->next->next;
        return dummy->next;
    }
};