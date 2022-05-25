class Solution {
public:
    bool isValid(string str) {
        stack<char> s;
        int n=str.size();
        for(int i=0; i<n; ++i){
            if(str[i]=='(') s.push('(');
            else if(str[i]=='{') s.push('{');
            else if(str[i]=='[') s.push('[');
            else if(str[i]==')'){
                if(s.empty()) return false;
                char b=s.top();
                s.pop();
                if(b!='(') return false;
            }
            else if(str[i]=='}'){
                if(s.empty()) return false;
                char b=s.top();
                s.pop();
                if(b!='{') return false;
            }
            else if(str[i]==']'){
                if(s.empty()) return false;
                char b=s.top();
                s.pop();
                if(b!='[') return false;
            }
        }
        if(!s.empty()) return false;
        return true;
    }
};