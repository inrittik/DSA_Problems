class MinStack {
public:
    stack<int> s, minHolder;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        
        if(minHolder.empty() || val<=minHolder.top()) minHolder.push(val);
    }
    
    void pop() {
        if(minHolder.top()==s.top()) minHolder.pop();
        
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minHolder.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */