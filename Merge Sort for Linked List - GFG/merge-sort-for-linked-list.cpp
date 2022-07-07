// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
  Node* middle(Node* head){
        Node* slow = head;
        Node* fast = head->next;

        while (!slow->next && (!fast && !fast->next)) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    Node* merge(Node* head, Node* head2){
        Node* merged = new Node(0);
        Node* temp = new Node(0);

        merged = temp;

        while (head != NULL && head2 != NULL) {
            if (head->data <= head2->data){
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
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
        if(head==NULL || head->next==NULL) return head;
        
        Node* mid = new Node(0);
        Node* head2 = new Node(0);
        mid = middle(head);
        head2 = mid->next;
        mid->next = NULL;
        
        Node* resHead = merge(mergeSort(head), mergeSort(head2));
        return resHead;
    }
};


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends