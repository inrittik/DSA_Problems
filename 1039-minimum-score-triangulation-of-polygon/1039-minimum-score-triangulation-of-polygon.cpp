class Solution {
public:
    int calcScore(vector<int>& values, int i, int j, vector<vector<int>>& dp){
        if(i==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mnScore = 0;
        for(int k=i+1; k<j; ++k){
            int score = calcScore(values, i, k, dp) + values[i] * values[k] * values[j] + calcScore(values, k, j, dp);
            mnScore = min(mnScore == 0 ? INT_MAX : mnScore, score);
        }
        
        return dp[i][j]=mnScore;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return calcScore(values, 0, values.size()-1, dp);
    }
};