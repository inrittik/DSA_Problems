class Solution {
public:
    pair<int, int> cntVal(vector<int>& arr, int i, int j, vector<vector<pair<int, int>>>& dp){
        // base cntd  
        if(i==j) return {0, arr[i]};
        
        if(dp[i][j].first!=-1 && dp[i][j].second!=-1) return dp[i][j];
        
        int mnSum = INT_MAX;
        int mxLeaf = INT_MIN;
        for(int k=i; k<j; ++k){
            pair<int, int> left = cntVal(arr, i, k, dp);
            pair<int, int> right = cntVal(arr, k+1, j, dp);
            
            mxLeaf = max(left.second, right.second);
            mnSum = min(mnSum, left.first+right.first+left.second*right.second);
        }
        return dp[i][j]={mnSum, mxLeaf};

    }
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {-1, -1}));
        pair<int, int> ans = cntVal(arr, 0, n-1, dp);
        return ans.first;
    }
};