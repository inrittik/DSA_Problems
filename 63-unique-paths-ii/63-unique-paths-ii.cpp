class Solution {
public:
    vector<vector<int>> dp;
    int getPath(vector<vector<int>>& obstacleGrid, int r, int c){
        if(obstacleGrid[r][c]==1) return 0;
        if(dp[r][c]>0) return dp[r][c];
        if(r==obstacleGrid.size()-1 && c==obstacleGrid[0].size()-1){
            return 1;
        }
        else if(r==obstacleGrid.size()-1){
            return dp[r][c] = getPath(obstacleGrid, r, c+1);
        }
        else if(c==obstacleGrid[0].size()-1){
            return dp[r][c] = getPath(obstacleGrid, r+1, c);
        }
        return dp[r][c] = getPath(obstacleGrid, r+1, c)+getPath(obstacleGrid, r, c+1);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        dp.resize(obstacleGrid.size(), vector<int>(obstacleGrid[0].size()));
        return getPath(obstacleGrid, 0, 0);
    }
};