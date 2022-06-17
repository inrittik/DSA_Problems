class Solution {
public:
    int minDistance(string s, string t) {
        vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1));
        int n = s.size(), m = t.size();
        for(int i=0; i<=n; ++i){
            dp[i][0]=i;
        }
        for(int j=0; j<=m; ++j){
            dp[0][j]=j;
        }
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                if(s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=1+min(min(dp[i-1][j-1], dp[i][j-1]), dp[i-1][j]);
            }
        }
        return dp[n][m];
    }
};