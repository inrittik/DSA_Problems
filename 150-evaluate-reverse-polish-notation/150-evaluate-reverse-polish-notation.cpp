class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(string s:tokens){
            if(s=="+" || s=="-" || s=="*" || s=="/"){
                if(st.empty()) break;
                
                int val2 = st.top();
                st.pop();
                int val1 = st.top();
                st.pop();
                int eval;
                if(s=="+") eval = val1+val2;
                else if(s=="-") eval = val1-val2;
                else if(s=="*") eval = val1*val2;
                else if(s=="/") eval = val1/val2;
                
                st.push(eval);
            }
            else{
                int val = stoi(s);
                st.push(val);
            }
        }
        
        return st.top();
    }
};