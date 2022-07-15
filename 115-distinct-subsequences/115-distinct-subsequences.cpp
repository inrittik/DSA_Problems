class Solution {
public:
    vector<vector<int>> dp;
    int helper(int n,int m,string &s,string &t)
    {
        if(m<0) return 1;
        if(n<0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        if(s[n]==t[m]){
            return dp[n][m]=helper(n-1,m-1,s,t)+helper(n-1,m,s,t);
        }
        return dp[n][m]=helper(n-1,m,s,t);
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        dp.resize(n, vector<int>(m, -1));
        return helper(n-1, m-1, s, t);
    }
};