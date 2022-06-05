class MyQueue {
public:
    stack<int> s;
    stack<int> ss;
    MyQueue() {
        
    }
    
    void push(int x) {
        s.push(x);
    }
    
    int pop() {
        if(ss.empty()){
            while(!s.empty()){
                ss.push(s.top());
                s.pop();
            }
            int p=ss.top();
            ss.pop();
            return p;
        }
        else{
            int p=ss.top();
            ss.pop();
            return p;
        }
    }
    
    int peek() {
        if(ss.empty()){
            while(!s.empty()){
                ss.push(s.top());
                s.pop();
            }
            int p=ss.top();
            return p;
        }
        else{
            int p=ss.top();
            return p;
        }
    }
    
    bool empty() {
        return (s.empty() && ss.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */