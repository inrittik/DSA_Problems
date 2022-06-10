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
    ListNode* partition(ListNode* tmp, int x) {
        ListNode* sm = new ListNode(0);
        ListNode* lr = new ListNode(0);        
        ListNode* sm_t = sm;
        ListNode* lr_t = lr;
        while(tmp){
            if(tmp->val<x){
                sm_t->next = tmp;
                sm_t = tmp;
            }
            else{
                lr_t->next = tmp;
                lr_t = tmp;
            }
            tmp = tmp->next;
        }
        lr_t->next = NULL;
        sm_t->next = lr->next;
        return sm->next;
    }
};