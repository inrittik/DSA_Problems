class Solution {
public:
    int ans = 0;
    vector<int> dp;
    void helper(string& s, int i, set<string>& st){
        if(i==s.size()) {
            ans++;
            return;
        }
        if(dp[i]!=-1) {
            ans += dp[i];
            return;
        }
        string num = "";
        for(int k=i; k<s.size(); ++k){
            num.push_back(s[k]);
            if(st.find(num)!=st.end()) helper(s, k+1, st);
        }
        dp[i] = ans;
    }
    int numDecodings(string s) {
        set<string> st;
        for(int i=1; i<=26; ++i){
            st.insert(to_string(i));
        }
        dp.resize(s.size(), -1);
        helper(s, 0, st);
        return ans;
    }
};