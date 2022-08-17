class Solution {
public:
    vector<vector<int>> dp;
    int helper(vector<vector<int>>& dungeon, int i, int j, int& m, int& n){
        if(i>=m || j>=n) return INT_MAX;

        if(i==m-1 && j==n-1) {
            return (dungeon[i][j]<=0)? -dungeon[i][j]+1:1;
        }

        if(dp[i][j]!=-1) return dp[i][j];
        int bottom, right;
        bottom = helper(dungeon, i+1, j, m, n);
        right = helper(dungeon, i, j+1, m, n);
        
        int mn = min(bottom, right) - dungeon[i][j];
        
        return dp[i][j]=(mn<=0)?1:mn;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        dp.resize(m, vector<int>(n, -1));
        return helper(dungeon, 0, 0, m, n);
    }
};