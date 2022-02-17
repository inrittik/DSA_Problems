// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

// Geeksforgeeks - Longest Common Substring
// Bottom Up Approach
class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        int dp[n+1][m+1];
        int res=0;
        for(int i=0; i<=n; ++i){
            dp[i][0]=0;
        }
        for(int j=0; j<=m; ++j){
            dp[0][j]=0;
        }
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                if(S1[i-1]==S2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                    res=max(res, dp[i][j]);
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        
        return res;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends


// Top Down Approach

  // { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    vector<vector<int>> dp;
    int maxm;
    int util(int n, int m, string &s1, string &s2)
    {
        if(n == 0 or m == 0)
            return 0;
        if(dp[n][m] != -1)
            return dp[n][m];
        if(s1[n-1] == s2[m-1])
            dp[n][m] = 1 + util(n-1,m-1,s1,s2);
        else
            dp[n][m] = 0;
        util(n,m-1,s1,s2);
        util(n-1,m,s1,s2);
        maxm = max(maxm,dp[n][m]);
        return dp[n][m];
    }
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        dp.resize(n+1, vector<int>(m+1, -1));
        maxm=INT_MIN;
        util(n, m, S1, S2);
        return maxm;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends