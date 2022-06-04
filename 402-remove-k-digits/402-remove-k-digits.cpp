class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        stack<char> st;
        int s = n-k;
        if(s==0) return "0";
        if(k==0) return num;
        st.push(num[0]);
        for(int i=1; i<n; ++i){
            while(k > 0 && !st.empty() && num[i] < st.top()){
                --k;
                st.pop();
            }
            
            st.push(num[i]);

            if(st.size() == 1 && num[i] == '0')
                st.pop();
        }
        while(k && !st.empty()){
            --k;
            st.pop();
        }
        string ans = "";
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        while(ans[0]=='0'){
            ans.erase(ans.begin());
        }
        if(ans.size()==0) ans="0";
        return ans;
    }
};