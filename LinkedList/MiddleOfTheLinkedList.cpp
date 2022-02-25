// Leetcode - Find Middle Node of the Linkked List

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* mid;
        ListNode* ptr;
        ptr=head;
        mid=head;
        while(ptr && ptr->next){
            ptr=ptr->next->next;
            mid=mid->next;
        }
        return mid;
    }
};