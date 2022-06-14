class Solution {
public:
    vector<vector<int>> dp;
    int helper(vector<vector<int>>& matrix, int ro, int co){
        if(ro==0 && co>=0 && co<matrix[0].size()) return matrix[ro][co];
        if(co<0 || co>=matrix[0].size()) return INT_MAX;
        if(dp[ro][co]!=-1) return dp[ro][co];
        
        int mn=INT_MAX;
        for(int i=co+1; i<matrix[0].size(); ++i){
            mn = min(mn, helper(matrix, ro-1, i));
        }
        for(int i=co-1; i>=0; --i){
            mn = min(mn, helper(matrix, ro-1, i));
        }
        return dp[ro][co]=matrix[ro][co]+mn;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int ans = INT_MAX;
        dp.resize(m, vector<int>(matrix[0].size(), -1));
        for(int i=0; i<m; ++i){
            ans = min(ans, helper(matrix, m-1, i));
        }
        return ans;
    }
};