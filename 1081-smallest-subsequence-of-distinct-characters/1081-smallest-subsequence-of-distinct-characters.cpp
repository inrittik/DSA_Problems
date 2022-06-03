class Solution {
public:
    string smallestSubsequence(string s) {
        int n=s.size();
        int lastInd[26];
        for(int i=0; i<n; ++i){
            lastInd[s[i]-'a'] = i;
        }
        vector<bool> isVis(26, false);
        
        stack<int> st;
        for(int i=0; i<n; ++i){
            int c=s[i]-'a';
            if(isVis[c]) continue;
            while(!st.empty() && st.top()>c && i<lastInd[st.top()]){
                isVis[st.top()] = false;
                st.pop();
            }
            st.push(c);
            isVis[c] = true;
        }
        
        string ans="";
        while(!st.empty()){
            ans.push_back(st.top()+'a');
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};