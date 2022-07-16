class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int n = s.size();
        int mxCnt = 0;
        for(int i=0; i<n; ++i){
            if(s[i]=='(') st.push(i);
            else if(!st.empty()){
                if(s[st.top()]=='(') st.pop();
                else st.push(i);
            }
            else st.push(i);
        }
        if(st.empty()) mxCnt = n;
        else{
            int a = n, b = 0;
            while (!st.empty()) {
                b = st.top(); st.pop();
                mxCnt = max(mxCnt, a-b-1);
                a = b;
            }
            mxCnt = max(mxCnt, a);
        }
        return mxCnt;
    }
};