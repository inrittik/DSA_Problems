struct Node{
    int val;
    Node* next;
    Node(int x){
        val = x;
    }
};

class MyCircularQueue {
public:
    Node* dummy = new Node(0);
    Node* Head = dummy;
    Node* Tail = dummy;
    int mxSz;
    int sz;
    MyCircularQueue(int k) {
        mxSz = k;
        sz = 0;
        Tail = Head;
    }
    
    bool enQueue(int value) {
        if(sz==mxSz) return false;
        if(sz==0){
            Tail->val = value;
            sz++;
            return true;
        }
        Tail->next = new Node(value);
        Tail = Tail->next;
        sz++;
        return true;
    }
    
    bool deQueue() {
        if(sz==0) return false;
        if(sz==1){
            Head = Tail;
            sz--;
            return true;
        }
        Head = Head->next;
        sz--;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return Head->val;
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return Tail->val;
    }
    
    bool isEmpty() {
        return sz==0;
    }
    
    bool isFull() {
        return sz == mxSz;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */