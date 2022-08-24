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
    int length(ListNode* head){
        int len = 0;
        ListNode* itr = head;
        while(itr){
            itr = itr->next;
            len++;
        }
        return len;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carr = 0;
        ListNode* itr1 = l1;
        ListNode* itr2 = l2;
        ListNode* pre = NULL;
        bool changed = false;
        if(length(l1)<length(l2)){
            itr1 = l2;
            itr2 = l1;
            changed = true;
        }
        while(itr1 && itr2){
            int val = itr1->val + itr2->val + carr;
            carr = val/10;
            val = val%10;
            itr1->val = val;
            pre = itr1;
            itr1 = itr1->next;
            itr2 = itr2->next;
        }
        while(itr1){
            int val = itr1->val + carr;
            carr = val/10;
            val = val%10;
            itr1->val = val;
            pre = itr1;
            itr1 = itr1->next;
        }
        if(carr!=0){
            pre->next = new ListNode(carr);
        }
        return changed?l2:l1;
    }
};