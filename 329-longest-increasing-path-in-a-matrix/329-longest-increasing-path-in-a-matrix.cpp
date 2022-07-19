class Solution {
public:
    vector<vector<int>> dp;
    int helper(vector<vector<int>>& matrix, int i, int j){
        int n = matrix.size();
        int m = matrix[0].size();
        
        if(dp[i][j]!=-1) return dp[i][j];
        int left = 1, right = 1, up = 1, down = 1;
        
        if(i<n-1 && matrix[i+1][j]>matrix[i][j]){
            down = 1+helper(matrix, i+1, j);
        }
        if(i>0 && matrix[i-1][j]>matrix[i][j]){
            up = 1+helper(matrix, i-1, j);
        }
        if(j<m-1 && matrix[i][j+1]>matrix[i][j]){
            right = 1+helper(matrix, i, j+1);
        }
        if(j>0 && matrix[i][j-1]>matrix[i][j]){
            left = 1+helper(matrix, i, j-1);
        }
        
        return dp[i][j]=max({left, right, up, down});
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int mxAns = 0;
        
        dp.resize(n, vector<int>(m, -1));
        
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                mxAns = max(mxAns, helper(matrix, i, j));
            }
        }
        
        return mxAns;
    }
};