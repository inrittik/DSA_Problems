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
    bool hasCycle(ListNode *head) {
        ListNode* slo = head;
        ListNode* fas = head;
        while(slo && fas && fas->next){
            slo = slo->next;
            fas = fas->next->next;
            
            if(slo==fas) return true;
        }
        
        return false;
    }
};