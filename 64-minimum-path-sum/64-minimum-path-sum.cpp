class Solution {
public:
    vector<vector<int>> dp;
    int helper(vector<vector<int>>& grid, int m, int n){
        if(m==0 && n==0) return grid[0][0];
        if(dp[m][n]!=-1) return dp[m][n];
        if(m==0) return dp[m][n]=grid[m][n]+helper(grid, m, n-1);
        if(n==0) return dp[m][n]=grid[m][n]+helper(grid, m-1, n);
        return dp[m][n]=grid[m][n]+min(helper(grid, m-1, n), helper(grid, m, n-1));
    }
    int minPathSum(vector<vector<int>>& grid) {
        dp.resize(grid.size(), vector<int>(grid[0].size(), -1));
        return helper(grid,grid.size()-1, grid[0].size()-1);
    }
};