class Solution {
public:
    vector<vector<int>> dp;
    bool helper(string& s, string& p, int n, int m){
        if(n==0 && m==0) return true;
        if(n==0){
            if(p[m-1]!='*') return false;
        }
        else if(m==0) return false;
        if(dp[n][m]!=-1) return dp[n][m];
        if(p[m-1]=='*' && n==0) return dp[n][m]=helper(s, p, n, m-1);
        if(s[n-1]==p[m-1] || p[m-1]=='?') return dp[n][m]=helper(s, p, n-1, m-1);
        else if(p[m-1]=='*') return dp[n][m]=helper(s, p, n-1, m) || helper(s, p, n-1, m-1) || helper(s, p, n, m-1);
        else return dp[n][m]=false;
        
    }
    bool isMatch(string s, string p) {
        dp.resize(s.size()+1, vector<int>(p.size()+1, -1));
        return helper(s, p, s.size(), p.size());
    }
};