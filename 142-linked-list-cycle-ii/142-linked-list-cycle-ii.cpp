/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slo = head;
        ListNode* fas = head;
        
        while(fas && fas->next){
            slo = slo->next;
            fas = fas->next->next;
            if(slo==fas) break;
        }
        
        if(fas==NULL || fas->next==NULL) return NULL;
        
        slo = head;
        while(slo!=fas){
            slo = slo->next;
            fas = fas->next;
        }
        return fas;
    }
};