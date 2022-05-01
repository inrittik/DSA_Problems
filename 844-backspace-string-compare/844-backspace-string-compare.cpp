class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1;
        stack<char> s2;
        int i=0;
        while(i<s.size()){
            if(s[i]=='#'){
                if(!s1.empty()) s1.pop();
                i++;
                continue;
            }
            s1.push(s[i++]);
        }
        i=0;
        while(i<t.size()){
            if(t[i]=='#'){
                if(!s2.empty()) s2.pop();
                i++;
                continue;
            }
            s2.push(t[i++]);
        }
        if(s1.size()!=s2.size()) return false;
        while(!s1.empty() and !s2.empty()){
            char x, y;
            x = s1.top();
            y = s2.top();
            s1.pop();
            s2.pop();
            if(x!=y) return false;
        }
        
        if(!s1.empty() or !s2.empty()){
            return false;
        }
        
        return true;
    }
};