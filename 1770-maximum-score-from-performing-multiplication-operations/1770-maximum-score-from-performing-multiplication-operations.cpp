class Solution {
public:
    int maximumScore(vector<int>& num, vector<int>& mul) {
        int n = num.size(), m = mul.size();
        vector<vector<int>> dp(m+1, vector<int>(m+1));
        for(int i=m-1; i>=0; --i){
            for(int j=m-1; j>=0; --j){
                dp[i][j] = max(num[j]*mul[i] + dp[i+1][j+1], num[n-1-abs(j-i)]*mul[i] + dp[i+1][j]);
            }
        }
        return dp[0][0];
    }
};