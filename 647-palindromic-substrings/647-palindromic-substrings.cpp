class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int cnt=n;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i=0; i<n; ++i) dp[i][i]=1;
        for(int i=n-1; i>=0; --i){
            for(int j=i+1; j<n; ++j){
                if(s[i]==s[j]){
                    if(j-i==1 || dp[i+1][j-1]){
                        dp[i][j]=1;
                        cnt++;
                    }
                }
            }
        }
        
        return cnt;
    }
};