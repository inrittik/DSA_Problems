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
    ListNode* reverseList(ListNode* head){
        ListNode* curr = head;
        ListNode* pre = NULL;
        ListNode* next = NULL;
        
        while(curr){
            next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        
        return pre;
    }
    ListNode* middlePtr(ListNode* head){
        if (head == NULL || head->next == NULL) return head;
        
        ListNode* slow = head; ListNode* fast = head;
        while (fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        if(head==NULL || head->next==NULL) return true;
        ListNode* rev = reverseList(middlePtr(head));
        
        while(rev && head){
            if(head->val != rev->val) return false;
            head = head->next;
            rev = rev->next;
        }
        return true;
    }
};