class Solution {
public:
    long long longestCommonSubsequence(string& s1, string& s2){
        int n = s1.size(), m = s2.size();
        vector<vector<long long>> dp(n+1, vector<long long>(m+1));
        for(int i=0; i<=n; ++i) dp[i][0]=0;
        for(int j=0; j<=m; ++j) dp[0][j]=0;
        
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                if(s1[i-1]==s2[j-1]) dp[i][j]=s1[i-1]+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
    int minimumDeleteSum(string s1, string s2) {
        long long ascii_total = 0;
        for(char c:s1) ascii_total+=c;
        for(char c:s2) ascii_total+=c;
        
        return ascii_total-2*longestCommonSubsequence(s1, s2);
    }
};