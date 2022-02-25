// Leetcode - Remove Nth node from the end

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return nullptr;

        ListNode new_head(-1);
        new_head.next = head;
        ListNode* fast=&new_head;
        ListNode* slow=&new_head;
        while(n>0){
            fast=fast->next;
            n--;
        }
        while(fast->next){
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        return new_head.next;
    }
};