class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        if(s.size()%2!=0) return false;
        for(char c:s){
            if(c=='(' || c=='{' || c=='[') st.push(c);
            else{
                if(st.empty()) return false;
                if(c==')' && st.top()!='(') return false;
                if(c=='}' && st.top()!='{') return false;
                if(c==']' && st.top()!='[') return false;
                
                if(!st.empty()) st.pop();
            }
        }
        
        return st.empty()? true:false;
    }
};