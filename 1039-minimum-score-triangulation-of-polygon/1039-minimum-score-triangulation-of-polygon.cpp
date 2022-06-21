class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1));
        for(int i=n-1; i>=0; --i){
            for(int j = i+1; j<n; ++j){
                int mnScore = 0;
                for(int k=i+1; k<j; ++k){
                    int score = dp[i][k] + values[i] * values[k] * values[j] + dp[k][j];
                    mnScore = min(mnScore == 0 ? INT_MAX : mnScore, score);
                }
        
                dp[i][j]=mnScore;
            }
        }
        return dp[0][n-1];
    }
};