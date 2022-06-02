class MinStack {
public:
    stack<long> s;
    long min_ele;
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()){
            s.push(val);
            min_ele=val;
        }
        else if(val>min_ele){
            s.push(val);
        }
        else if(val<=min_ele){
            s.push((long)2*val-min_ele);
            min_ele=val;
        }
    }
    
    void pop() {
        if(!s.empty()){
            if(s.top()>min_ele){
                s.pop();
            }
            else{
                min_ele=2*min_ele-s.top();
                s.pop();
            }
        }
    }
    
    int top() {
        if(s.empty()) return -1;
        if(s.top()>min_ele) return s.top();
        else return min_ele;
    }
    
    int getMin() {
        if(s.empty()) return -1;
        else return min_ele;
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