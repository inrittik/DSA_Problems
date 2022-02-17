// Leetcode - Shortest Common Supersequence(print)

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        int dp[n+1][m+1];
        for(int i=0; i<=n; ++i){
            dp[i][0]=0;
        }
        for(int j=0; j<=m; ++j){
            dp[0][j]=0;
        }
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        int i=n, j=m;
        string s;
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                s.push_back(str1[i-1]);
                i--, j--;
            }
            else{
                if(dp[i-1][j]>dp[i][j-1]){
                    s.push_back(str1[i-1]);
                    i--;
                }
                else{
                    s.push_back(str2[j-1]);
                    j--;
                }
            }
        }
        while(i>0){
            s.push_back(str1[i-1]);
            i--;
        }
        while(j>0){
            s.push_back(str2[j-1]);
            j--;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};