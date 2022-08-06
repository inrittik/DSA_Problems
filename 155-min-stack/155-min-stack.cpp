class MinStack {
public:
    stack<int> s;
    int minVal = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        if(val<=minVal) {
            s.push(minVal);
            minVal = val;
        }
            
        s.push(val);
    }
    
    void pop() {
        if(minVal==s.top()) {
            s.pop();
            minVal = s.top();
        }
        
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minVal;
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