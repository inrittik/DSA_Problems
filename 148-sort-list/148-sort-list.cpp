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
    ListNode* merge(ListNode* head, ListNode* head2){
        ListNode* merged = new ListNode;
        ListNode* temp = new ListNode;

        merged = temp;

        while (head != NULL && head2 != NULL) {
            if (head->val <= head2->val){
                temp->next = head;
                head = head->next;
            }
            else{
                temp->next = head2;
                head2 = head2->next;
            }
            temp = temp->next;
        }

        while (head != NULL){
            temp->next = head;
            head = head->next;
            temp = temp->next;
        }

        while (head2 != NULL){
            temp->next = head2;
            head2 = head2->next;
            temp = temp->next;
        }
        return merged->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        
        ListNode *temp = NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast !=  NULL && fast -> next != NULL){
            temp = slow;
            slow = slow->next;
            fast = fast ->next ->next;
            
        }   
        temp -> next = NULL;
        
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);
        
        ListNode* resHead = merge(l1, l2);
        return resHead;
    }
};