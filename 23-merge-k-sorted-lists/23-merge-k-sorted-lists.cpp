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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=lists.size();
        auto comp = [&](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);
        for (ListNode* node:lists)
            if (node!=NULL)
                pq.push(node);
        ListNode* head = new ListNode(0);
        ListNode* tmp = head;
        while(!pq.empty()){
            tmp->next = pq.top();
            pq.pop();
            tmp = tmp->next;
            if (tmp->next!=NULL)
                pq.push(tmp->next);
        }
        return head->next;
    }
};